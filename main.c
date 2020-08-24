//#include "GLApply.h"
//#include "GLApi.h"
//
//
//// 野鸡内部 api，先暴露出来让人能用
//static GLVariable *
//_GLVariableCreateByBuiltinFunction(GLFunctionBuiltinFunctionPointer func);
//
//static GLVariable *
//_GLVariableCreateByBuiltinFunction(GLFunctionBuiltinFunctionPointer func) {
//    return  GLVariableCreate(GLValueCreate(GLValueTypeFunctionBuiltin, GLFunctionBuiltinCreate(func)), false);
//}
//
//// 注册给 gualang 的函数统一长下面这样
//GLValue *
//GLAddBlock(GLValue *args) {
//    // 解析参数
//    GuaList *l = GLApiValueToList(args);
//    GLValue *vx = GuaListElementByIndex(l, 0);
//    int x = GLApiValueToInt(vx);
//
//    printf("add block %d\n", x);
//
//    // 没有返回值，返回 null
//    return GLValueCreateNull();
//}
//
//int
//main(void) {
//    // 解释器需要一个字典来存变量，在 gualang 里叫 GLScope
//    GLScope *vars = GLScopeCreate();
//
//    // 把 addBlock 塞到 vars 里
//    GLScopeSet(vars, "addBlock", _GLVariableCreateByBuiltinFunction(GLAddBlock));
//
//    // dofile
//    char *path = "test.gua";
//    GLApplyWithFileContentAndScope(path, vars, true);
//}


#include "utils.h"
#include "guaList.h"


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
drawGuagameList(GuagameList *list) {
    int len = list->length;
    int i;
    for (i = 0; i < len; i += 1) {
        GuagameNode *node = (list->elements)[i];
        GuagameNodeDraw(node);
    }
}

void
addNodeToList(GuagameNode *node, GuagameList *list) {
    // 把node放入到list中
    // todo:需要做超界判断，先不做
    const int i = list->length;
    list->elements[i] = node;
    list->length += 1;
}

// ptm和mtp可以抽
// x, y可以做成vect
void
addNode(int type, x, y, GuagameList *list, cpSpace *space) {
    GuagameNode *node = GuagameNodeBoxNew(space, imgPaths[type]);
    GuagameNodeSetPosition(node, x, y);
    addNodeToList(node, list);
}

void
addNodeByConfig(char *str, GuagameList *list, cpSpace *space) {
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
updateByConfig(GuagameList *list, cpSpace *space) {
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
    // 解释器需要一个字典来存变量，在 gualang 里叫 GLScope
//    GLScope *vars = GLScopeCreate();
//
//    // 把 addBlock 塞到 vars 里
//    GLScopeSet(vars, "addBlock", _GLVariableCreateByBuiltinFunction(GLAddBlock));
//
//    // dofile
//    char *path = "test.gua";
//    GLApplyWithFileContentAndScope(path, vars, true);



    InitWindow(windowWidth, windowHeight, "yanhui");
    SetTargetFPS(60);

    Texture2D bg = LoadTexture("resources/angryBirds_bg.png");

    // 物理空间
    cpSpace *space = cpSpaceNew();
    cpSpaceSetGravity(space, cpv(ptm(0), ptm(1000)));

    // 设置墙面
    setWall(space);

    GuagameList *list = createGuagameList();

//    char config[] = "100 00 1";
//    addNodeByConfig(config, list, space);

    // 先落
    addNode(BASE, 0, 150, list, space);
    // 特殊对象 单独加，小鸟后落
    GuagameNode *bird = GuagameNodeNew(space, imgPaths[BIRD]);
    GuagameNodeSetPosition(bird, 20, 00);
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
            drawGuagameList(list);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

