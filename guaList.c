//
//  guaList.c
//  guagame
//
//  Created by bytedance on 2020/8/21.
//  Copyright © 2020 axe. All rights reserved.
//

#include "guaList.h"

GuagameList *
createGuagameList() {
    GuagameList *list = (GuagameList*)malloc(sizeof(GuagameList));
    list->size = 100;
    list->length = 0;
    list->elements = (GuagameNode**)malloc(sizeof(GuagameNode*) * list->size);
    return list;
}
