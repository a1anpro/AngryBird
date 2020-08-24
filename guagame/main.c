#include "utils.h"
#include "guaList.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>


long int
getCreateTime() {
    struct stat buf;
    int result = stat("/Users/bytedance/axe/raylib/angryBird/bird/guagame/config", &buf );
    long int createTime = 0;
    if( result != 0 )
        perror( "显示文件状态信息出错" );
    else
    {
        createTime = buf.st_ctime;
        printf("文件创建时间: %ld\n", createTime);
    }
    return createTime;
}

long int
getModifiedTime() {
    struct stat buf;
    int result = stat("/Users/bytedance/axe/raylib/angryBird/bird/guagame/config", &buf );
    long int modifiedTime = 0;
    if( result != 0 )
        perror( "显示文件状态信息出错" );
    else
    {
        modifiedTime = buf.st_mtime;
//        printf("文件修改时间: %ld\n", modifiedTime);
    }
    return modifiedTime;
}

enum Object{PIG, BIRD, BASE, BLOCK1, BLOCK1V, BLOCK3, BLOCK3V};
const char *imgPaths[] = {
    "resources/pig.png",
    "resources/bird.png",
    "resources/base.png",
    "resources/block1.png",
    "resources/block1v.png",
    "resources/block3.png",
    "resources/block3v.png"
};

cpBool
begin(cpArbiter *arb, cpSpace *space, cpDataPointer userData) {
//    printf("begin \n");
    
    return true;
}

// 一步步抽，
// 先把所有元素聚合起来，让他们自己画自己
// 再抽成场景，让场景去画他们

void
drawGuaList(GuaList *list) {
    int len = list->length;
    int i;
    for (i = 0; i < len; i += 1) {
        GuaNode *node = (list->elements)[i];
        GuaNodeDraw(node);
    }
}

void
addNodeToList(GuaNode *node, GuaList *list) {
    // 把node放入到list中
    // todo:需要做超界判断，先不做
    const int i = list->length;
    list->elements[i] = node;
    list->length += 1;
}

// ptm和mtp可以抽
// x, y可以做成vect
void
addNode(int type, x, y, GuaList *list, cpSpace *space) {
    GuaNode *node = GuaNodeBoxNew(space, imgPaths[type]);
    GuaNodeSetPosition(node, x, y);
    addNodeToList(node, list);
}

void
addNodeByConfig(char *str, GuaList *list, cpSpace *space) {
    char *ptr;
    ptr = strtok(str, " ");
    
    int i = 0;
    
    int x = 0;
    int y = 0;
    int type = 0;
    
    while (ptr != NULL) {
        if (i == 0) {
            x = atoi(ptr);
        } else if (i == 1) {
            y = atoi(ptr);
        } else if (i == 2){
            type = atoi(ptr);
        }
        ptr = strtok(NULL, " ");
        i += 1;
    }
    addNode(type, x, y, list, space);
}

void
updateByConfig(GuaList *list, cpSpace *space) {
    FILE *fp = NULL;
    fp = fopen("/Users/bytedance/axe/raylib/angryBird/bird/guagame/config", "r");
    char StrLine[1024];
    while (!feof(fp))
    {
        fgets(StrLine, 1024,fp);
        addNodeByConfig(StrLine, list, space);
    }
    fclose(fp);
}

int
main(int argc, const char * argv[]) {
    InitWindow(windowWidth, windowHeight, "yanhui");
    SetTargetFPS(60);
    
    Texture2D bg = LoadTexture("resources/angryBirds_bg.png");
    
    // 物理空间
    cpSpace *space = cpSpaceNew();
    cpSpaceSetGravity(space, cpv(ptm(0), ptm(1000)));
    
    // 设置墙面
    setWall(space);
    
    GuaList *list = createGuaList();
    
//    char config[] = "100 00 1";
//    addNodeByConfig(config, list, space);
    
    // 先落
    addNode(BASE, 0, 150, list, space);
    // 特殊对象 单独加，小鸟后落
    GuaNode *bird = GuaNodeNew(space, imgPaths[BIRD]);
    GuaNodeSetPosition(bird, 20, 00);
    addNodeToList(bird, list);
    cpShapeSetCollisionType(bird->shape, 100);
    
    addNode(PIG, 350, 30, list, space);
    addNode(BLOCK3, 380, 100, list, space);
    addNode(BLOCK3, 320, 100, list, space);
    addNode(BLOCK1V, 350, 60, list, space);
    
    
    cpCollisionHandler *handler = cpSpaceAddCollisionHandler(space, 100, 0);
    handler->beginFunc = begin;
    
    int force = 0;
    
    // 获取创建时间
    lastModifiedTime = getCreateTime();
    
    while (!WindowShouldClose()) {
        long int m = getModifiedTime();
        if (m != lastModifiedTime) {
            printf("文件改变\n");
            updateByConfig(list, space);
            lastModifiedTime = m;
        }
        if (IsKeyDown(KEY_SPACE)) {
            force += 1000;
            printf("add force %d\n", force);
        }
        if (IsKeyReleased(KEY_SPACE)) {
            printf("apply force %d\n", force);
            force = ptm(force);
            cpBodyApplyForceAtLocalPoint(bird->body, cpv(force, force*-1*0.25), cpv(0, 0));
            force = 0;
        }
        
        cpSpaceStep(space, 1.0/60.0);
        
        // Draw
        BeginDrawing();
            // 画不出了来预期的 应该到这里找
            ClearBackground(RAYWHITE);
            DrawTexture(bg, 0, 0, WHITE);
            drawGuaList(list);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
