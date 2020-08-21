//
//  guaList.h
//  guagame
//
//  Created by bytedance on 2020/8/21.
//  Copyright © 2020 axe. All rights reserved.
//

#ifndef guaList_h
#define guaList_h

#include <stdio.h>
#include "utils.h"

typedef struct GuaList {
    int length;
    int size;
    GuaNode **elements;
} GuaList;

GuaList *
createGuaList();


#endif /* guaList_h */
