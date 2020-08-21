//
//  utils.h
//  guagame
//
//  Created by alan on 2020/8/21.
//  Copyright © 2020 axe. All rights reserved.
//

#ifndef utils_h
#define utils_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/raylib.h"
#include "includes/chipmunk.h"

// 上次修改的时间
static long int lastModifiedTime = 0;

typedef struct GuaNode {
    float x;
    float y;
    // 皮肤
    Texture2D texture;
    // 物理body
    cpBody *body;
    // 形状
    cpShape *shape;
} GuaNode;


static const int windowWidth = 960;

static const int windowHeight = 320;

static const float pixelsPerMeter = 100.0;

// 像素传给物理世界
static inline float ptm(const float value) {
    return value / pixelsPerMeter;
}

// 物理世界传给像素
static inline float mtp(const float value) {
    return value * pixelsPerMeter;
}

void
printGuaNode(GuaNode *node);

void
setWall(cpSpace *space);

void
GuaNodeDraw(GuaNode *node);

void
GuaNodeSetPosition(GuaNode *node, float x, float y);

GuaNode *
GuaNodeNew(cpSpace *space, const char *path);

// 新建circle的node
GuaNode *
GuaNodeCircleNew(cpSpace *space, const char *path);

GuaNode *
GuaNodeBoxNew(cpSpace *space, const char *path);

#endif /* utils_h */
