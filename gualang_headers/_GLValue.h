//
//  _GLValue.h
//  cgualang
//
//  Created by 一 on 2020/7/6.
//  Copyright © 2020 一. All rights reserved.
//

#ifndef _GLValue_h
#define _GLValue_h


#include "GuaType.h"


enum _GLValueType;
typedef enum _GLValueType GLValueType;
enum _GLValueType {
    // 这里 0 保留用来标记数组的结尾
    GLValueTypeInt = 1,
    GLValueTypeFloat,
    GLValueTypeBool,
    GLValueTypeString,
    GLValueTypeNull,
    GLValueTypeUndefined,
    GLValueTypeInterrupt,
    GLValueTypeFunction,
    GLValueTypeFunctionBuiltin,
    GLValueTypeFunctionBuiltinLegacy,
    GLValueTypeMethod,
    GLValueTypeMethodBuiltin,  // builtin object 的方法，比如 GLArray 的 cut
    GLValueTypeMethodBuiltinPython,  // builtin object 的方法里没有，然后从 python 里找的 方法，比如 string.lstrip 等等
    GLValueTypeScope,
    GLValueTypeObject,  // gualang 用 map 来模拟 object，为了和 map 加以区分，多加一个 type
    GLValueTypeObjectBuiltin,
    GLValueTypeType,
    GLValueTypeGuaPyObject,
    GLValueTypeUserData,
    GLValueTypeStruct,
    GLValueTypeFFIType,
};


struct _GLValue;
typedef struct _GLValue GLValue;
struct _GLValue {
    GuaType _type;
    GLValueType type;
    void *value;
    int ref;
};


#endif /* _GLValue_h */
