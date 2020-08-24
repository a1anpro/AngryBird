//
//  GLFFIType.h
//  cgualang
//
//  Created by cai on 2020/8/11.
//  Copyright © 2020 一. All rights reserved.
//

#ifndef GLFFIType_h
#define GLFFIType_h

#include <stdio.h>
#include "GuaList.h"

enum _GLFFITypeType;
typedef enum _GLFFITypeType GLFFITypeType;
enum _GLFFITypeType {
    GLFFITypeTypeVoid = 1,
    GLFFITypeTypeUint8,
    GLFFITypeTypeSint8,
    GLFFITypeTypeUint16,
    GLFFITypeTypeSint16,
    GLFFITypeTypeUint32,
    GLFFITypeTypeSint32,
    GLFFITypeTypeUint64,
    GLFFITypeTypeSint64,
    GLFFITypeTypeFloat,
    GLFFITypeTypeDouble,
    GLFFITypeTypePointer,
    GLFFITypeTypeStruct,
    GLFFITypeTypeUchar,
    GLFFITypeTypeSchar,
    GLFFITypeTypeSint,
    GLFFITypeTypeUint,
};

struct _GLFFIType;
typedef struct _GLFFIType GLFFIType;

struct _GLFFITypeField;
typedef struct _GLFFITypeField GLFFITypeField;

struct _GLFFIType {
    GLFFITypeType ffiType;
    // type 是 libffi 中的 type
    void *type;
    int count;
    GLFFITypeField **fields;
    
    // 如果 ffiType 为 pointer，这个 ref 是 pointer 的类型
    GLFFIType *ref;
};

struct _GLFFITypeField {
    char *name;
    GLFFIType *type;
};

GLFFIType *
GLFFITypeCreateBasic(GLFFITypeType ffiType, void *type);

GLFFIType *
GLFFITypeCreatePointer(GLFFIType *ref);

GLFFIType *
GLFFITypeCreateStruct(void *type, int count, GLFFITypeField **fields);

GLFFITypeField *
GLFFITypeFieldCreate(char *name, GLFFIType *type);

#endif /* GLFFIType_h */
