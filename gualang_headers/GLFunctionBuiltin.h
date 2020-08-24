#ifndef GLFunctionBuiltin_h
#define GLFunctionBuiltin_h


#include "GuaType.h"

#include "GLValue.h"


typedef GLValue *(*GLFunctionBuiltinFunctionPointer)(GLValue *args);


struct _GLFunctionBuiltin;
typedef struct _GLFunctionBuiltin GLFunctionBuiltin;
struct _GLFunctionBuiltin {
    GuaType _type;
    GLFunctionBuiltinFunctionPointer function;
};


GLFunctionBuiltin *
GLFunctionBuiltinCreate(GLFunctionBuiltinFunctionPointer function);

int
GLFunctionBuiltinFree(GLFunctionBuiltin *f);


#endif /* GLFunctionBuiltin_h */
