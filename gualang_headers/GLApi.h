//
//  GLApi.h
//  cgualang
//
//  Created by cai on 2020/8/3.
//  Copyright © 2020 一. All rights reserved.
//

#ifndef GLApi_h
#define GLApi_h

#if defined(_WIN32)
    #define GLAPI __declspec(dllimport)     // We are using raylib as a Win32 shared library (.dll)
#else
    #define GLAPI       // We are building or using raylib as a static library (or Linux shared library)
#endif

#include <stdbool.h>

#include "GLValue.h"
#include "GLModule.h"
#include "GLFFIType.h"
#include "GLStruct.h"

GLAPI GLValue *
GLApiModuleCreate(GLModuleFunctionDef functions[]);

GLAPI void *
GLApiValueToVoid(GLValue *v);

GLAPI int
GLApiValueToInt(GLValue *v);

//long
//GLApiValueToLong(GLValue *v);

GLAPI float
GLApiValueToFloat(GLValue *v);

//double
//GLApiValueToDouble(GLValue *v);

GLAPI char *
GLApiValueToString(GLValue *v);

GLAPI bool
GLApiValueToBool(GLValue *v);

GLAPI GuaList *
GLApiValueToList(GLValue *v);

GLAPI GuaMap *
GLApiValueToMap(GLValue *v);

GLAPI void *
GLApiValueToUserData(GLValue *v);

GLAPI GLFFIType *
GLApiValueToFFIType(GLValue *v);

GLAPI GLStruct *
GLApiValueToStruct(GLValue *v);

GLAPI GLValue *
GLApiValueFromInt(int v);

//GLValue *
//GLApiValueFromLong(long v);

GLAPI GLValue *
GLApiValueFromFloat(float v);

//GLValue *
//GLApiValueFromDouble(double v);

GLAPI GLValue *
GLApiValueFromString(char *v);

GLAPI GLValue *
GLApiValueFromBool(bool b);

GLAPI GLValue *
GLApiValueFromList(GuaList *v);

GLAPI GLValue *
GLApiValueFromMap(GuaMap *v);

GLAPI GLValue *
GLApiValueFromUserData(void *v);

GLAPI GLValue *
GLApiValueFromFFIType(GLFFIType *v);

GLAPI GLValue *
GLApiValueFromStruct(GLStruct *v);

GLAPI GLValue *
GLApiValueFromNull(void);

#endif /* GLApi_h */
