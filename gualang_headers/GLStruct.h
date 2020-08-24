//
//  GLStruct.h
//  cgualang
//
//  Created by cai on 2020/8/10.
//  Copyright © 2020 一. All rights reserved.
//

#ifndef GLStruct_h
#define GLStruct_h

#include <stdio.h>
#include <stdbool.h>

#include "GLValue.h"
#include "GLFFIType.h"

struct _GLStruct;
typedef struct _GLStruct GLStruct;
struct _GLStruct {
    GLFFIType *ffiType;
    void *_struct;
};

/*
 malloc new struct 接口
 */
GLStruct *
GLStructCreate(GLFFIType *ffiType, void *_struct);

GLStruct *
GLStructMalloc(GLFFIType *f, int n);

///*
// 获取指针，对应于 c 语言的 &
// */
//GLStruct *
//GLStructRef(GLStruct *v);
//
///*
// 根据指针获取值，对应于 c 语言的 *
// */
//GLStruct *
//GLStructDeref(GLStruct *v);

bool
GLStructFieldSet(GLValue *s, char *name, GLValue *value);

GLValue *
GLStructFieldGet(GLValue *s, char *name);

bool
GLStructFieldHas(GLValue *s, char *name);

#endif /* GLStruct_h */
