//
//  guaList.c
//  guagame
//
//  Created by bytedance on 2020/8/21.
//  Copyright © 2020 axe. All rights reserved.
//

#include "guaList.h"

GuaList *
createGuaList() {
    GuaList *list = (GuaList*)malloc(sizeof(GuaList));
    list->size = 100;
    list->length = 0;
    list->elements = (GuaNode**)malloc(sizeof(GuaNode*) * list->size);
    return list;
}
