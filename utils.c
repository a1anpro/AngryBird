//
//  utils.c
//  guagame
//
//  Created by alan on 2020/8/21.
//  Copyright © 2020 axe. All rights reserved.
//

#include "utils.h"


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

void
setWall(cpSpace *space) {
    // 墙面只用设置一下就可 不用画出来，画出来就是drawLine一下即可
    // DrawLine(0, 0, windowWidth, 0, RED);
    // 用raylib的api画图，这是像素世界的
    int borderX = 0;
    int borderY = 0;
    int borderW = windowWidth;
    // 地面
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
}


GuagameNode *
GuagameNodeNew(cpSpace *space, const char *path) {
    // 物体质量，别管单位是什么
    float mass = 1;
    // 转动惯量，总之就是个名词
    float moment = 10;
    
    GuagameNode *n = malloc(sizeof(GuagameNode));
    n->texture = LoadTexture(path);;
    
    cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    n->body = body;
    
    float radius = ptm(n->texture.width / 2);
    
    
    cpShape *shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
    n->shape = shape;
    
    cpShapeSetCollisionType(shape, 100);
    cpShapeSetFriction(shape, 0.75);
    cpShapeSetElasticity(shape, 0.75);
    
    return n;
}

void
GuagameNodeSetPosition(GuagameNode *node, float x, float y) {
    cpBody *ballBody = node->body;
    cpBodySetPosition(ballBody, cpv(ptm(x), ptm(y)));
}

void
printGuagameNode(GuagameNode *node){
    printf("(%g, %g)\n", node->x, node->y);
}

void
GuagameNodeDraw(GuagameNode *node) {
    //    printGuagameNode(node);
    Vector2 p = {
        0, 0,
    };
    
    cpBody *body = node->body;
    // 通过body在物理世界space里拿到position
    cpVect position = cpBodyGetPosition(body);
    
    p.x = mtp(position.x);
    p.y = mtp(position.y);
    
    float angle = cpBodyGetAngle(body);
    
    // 拿到皮肤 转皮肤
    Texture2D texture = node->texture;
    
    float w = texture.width;
    float h = texture.height;
    
    Rectangle src = {0.0f, 0.0f, w, h};
    Rectangle dest = {p.x, p.y, w, h};
    Vector2 origin = {w/2, h/2};
    
    // 最后旋转看群里有两种方法， 用第二种
    // 1. 用 cpBodySetAngle api，算弧度
    // 2. 用 DrawTexturePro api，指定角度
    // NOTE: Using DrawTexturePro() we can easily rotate and scale the part of the texture we draw
    // sourceRec defines the part of the texture we use for drawing
    // destRec defines the rectangle where our texture part will fit (scaling it to fit)
    // origin defines the point of the texture used as reference for rotation and scaling
    // rotation defines the texture rotation (using origin as rotation point)
    DrawTexturePro(texture, src, dest, origin, angle*57.30f, WHITE);
}


GuagameNode *
GuagameNodeCircleNew(cpSpace *space, const char *path) {
    // 物体质量，别管单位是什么
    float mass = 1;
    // 转动惯量，总之就是个名词
    float moment = 10;
    
    GuagameNode *n = malloc(sizeof(GuagameNode));
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

GuagameNode *
GuagameNodeBoxNew(cpSpace *space, const char *path) {
    // 物体质量，别管单位是什么
    float mass = 1;
    // 转动惯量，总之就是个名词
    float moment = 10;
    
    GuagameNode *n = malloc(sizeof(GuagameNode));
    
    // 贴图 用来显示的...
    Texture2D texture = LoadTexture(path);
    n->texture = texture;
    
    // body是物理世界来用的，比如质量什么的
    cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    n->body = body;
    
    float w = ptm(texture.width);
    float h = ptm(texture.height);
    float radius = ptm(1.0);
    
    // 形状是用来描述样形状的
    cpShape *shape = cpSpaceAddShape(space, cpBoxShapeNew(body, w, h, radius));
    n->shape = shape;
    
    cpShapeSetFriction(shape, 0.75);
    cpShapeSetElasticity(shape, 0.75);
    
    return n;
}
