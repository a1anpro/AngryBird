#include "includes/raylib.h"
#include "includes/chipmunk.h"


static const float pixelsPerMeter = 100.0;

// 像素传给物理世界
static inline float ptm(const float value) {
    return value / pixelsPerMeter;
}

// 物理世界传给像素
static inline float mtp(const float value) {
    return value * pixelsPerMeter;
}

typedef struct GuaNode {
    Texture2D texture;
    cpBody *body;
    cpShape *shape;
} GuaNode;

GuaNode *
GuaNodeCircleNew(cpSpace *space, const char *path) {
    // 物体质量，别管单位是什么
    float mass = 1;
    // 转动惯量，总之就是个名词
    float moment = 10;
    
    GuaNode *n = malloc(sizeof(GuaNode));
    Texture2D texture = LoadTexture(path);
    n->texture = texture;
    
    cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    n->body = body;
    
    float radius = ptm(texture.width);
    cpShape *shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
    n->shape = shape;
    
    cpShapeSetFriction(shape, 1);
    cpShapeSetElasticity(shape, 0.75);

    return n;
}

GuaNode *
GuaNodeBoxNew(cpSpace *space, const char *path) {
    // 物体质量，别管单位是什么
    float mass = 1;
    // 转动惯量，总之就是个名词
    float moment = 10;
    
    GuaNode *n = malloc(sizeof(GuaNode));
    Texture2D texture = LoadTexture(path);
    n->texture = texture;
    
    cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    n->body = body;
    
    float w = ptm(texture.width);
    float h = ptm(texture.height);
    float radius = ptm(1.0);
    
    cpShape *shape = cpSpaceAddShape(space, cpBoxShapeNew(body, w, h, radius));
    n->shape = shape;
    
    cpShapeSetFriction(shape, 0.75);
    cpShapeSetElasticity(shape, 0.75);

    return n;
}

void
GuaNodeSetPosition(GuaNode *node, float x, float y) {
    cpBody *ballBody = node->body;
    cpBodySetPosition(ballBody, cpv(ptm(x), ptm(y)));
}

void
GuaNodeDraw(GuaNode *node) {
    Vector2 p = {
        0, 0,
    };
    
    cpBody *body = node->body;
    cpVect position = cpBodyGetPosition(body);
    
    p.x = mtp(position.x);
    p.y = mtp(position.y);
    
    float angle = cpBodyGetAngle(body);
    // printf("angle %f\n", angle);
    
    Texture2D texture = node->texture;
    
    float w = texture.width;
    float h = texture.height;
    
    Rectangle src = {0.0f, 0.0f, w, h};
    Rectangle dest = {p.x, p.y, w, h};
    Vector2 origin = {w/2, h/2};
    
    DrawTexturePro(texture, src, dest, origin, angle*57.30f, WHITE);
}

cpBool
begin(cpArbiter *arb, cpSpace *space, cpDataPointer userData) {
    printf("begin \n");

    return true;
}

int
main(int argc, const char * argv[]) {
    InitWindow(960, 320, "guagame");
    SetTargetFPS(60);
    
    Texture2D bg = LoadTexture("resources/angryBirds_bg.png");
    
    // 物理空间
    cpSpace *space = cpSpaceNew();
    cpSpaceSetGravity(space, cpv(ptm(0), ptm(1000)));
    
    int borderX = 0;
    int borderY = 0;
    int borderW = 960;
    int borderH = 240;
    
    cpVect points[4] = {
        cpv(borderX, borderY),
        cpv(borderX + borderW, borderY),
        cpv(borderX + borderW, borderY + borderH),
        cpv(borderX, borderY + borderH),
    };
    for (int i = 0; i < 4; i++) {
        cpVect p1 = points[i];
        cpVect p2 = points[(i+1)%4];
        
        cpVect q1 = {ptm(p1.x), ptm(p1.y)};
        cpVect q2 = {ptm(p2.x), ptm(p2.y)};
        
        cpShape *groundShape = cpSpaceAddShape(space, cpSegmentShapeNew(cpSpaceGetStaticBody(space), q1, q2, 0));
        cpShapeSetFriction(groundShape, 1);
        cpShapeSetElasticity(groundShape, 1);
    }
    
    GuaNode *bird = GuaNodeBoxNew(space, "resources/bird.png");
    GuaNodeSetPosition(bird, 150, 200);

    GuaNode *base1 = GuaNodeBoxNew(space, "resources/base.png");
    GuaNodeSetPosition(base1, 350, 150);
    
    GuaNode *block2 = GuaNodeBoxNew(space, "resources/block3.png");
    GuaNodeSetPosition(block2, 380, 100);
    
    GuaNode *block3 = GuaNodeBoxNew(space, "resources/block3.png");
    GuaNodeSetPosition(block3, 320, 100);

    GuaNode *block1 = GuaNodeBoxNew(space, "resources/block1v.png");
    GuaNodeSetPosition(block1, 350, 60);
    
    GuaNode *pig1 = GuaNodeBoxNew(space, "resources/pig.png");
    GuaNodeSetPosition(pig1, 350, 30);
    
    cpShapeSetCollisionType(bird->shape, 100);
    cpCollisionHandler *handler = cpSpaceAddCollisionHandler(space, 100, 0);
    handler->beginFunc = begin;
    
    int force = 0;
    while (!WindowShouldClose()) {
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
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
       
        DrawTexture(bg, borderX, borderY, WHITE);

        // for (int i = 0; i < 4; i++) {
        //     cpVect p1 = points[i];
        //     cpVect p2 = points[(i+1)%4];
        //     DrawLine(p1.x, p1.y, p2.x, p2.y, RED);
        // }
        
        GuaNodeDraw(bird);
        GuaNodeDraw(base1);
        GuaNodeDraw(block2);
        GuaNodeDraw(block3);
        GuaNodeDraw(block1);
        GuaNodeDraw(pig1);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
