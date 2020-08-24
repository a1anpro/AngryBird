//
//  guaScene.h
//  guagame
//
//  Created by bytedance on 2020/8/21.
//  Copyright © 2020 axe. All rights reserved.
//

#ifndef guaScene_h
#define guaScene_h

#include <stdio.h>
#include "utils.h"
#include "guaList.h"


// scene里包括画图、键盘事件、更新
// 需要查一下c的函数指针，调用函数

typedef struct GuaScene {
    GuagameList *elements;
} GuaScene;


#endif /* guaScene_h */
