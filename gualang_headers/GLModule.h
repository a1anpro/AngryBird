#ifndef GLModule_h
#define GLModule_h


#include "GLValue.h"
#include "GLFunctionBuiltin.h"


struct _GLModuleFunctionDef;
typedef struct _GLModuleFunctionDef GLModuleFunctionDef;
struct _GLModuleFunctionDef {
    char *name;
    GLFunctionBuiltinFunctionPointer function;
};

GLValue *
GLModuleCreate(GLModuleFunctionDef functions[]);


#endif /* GLModule_h */
