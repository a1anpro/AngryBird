#ifndef GLFunctionBuiltinLegacy_h
#define GLFunctionBuiltinLegacy_h


#include "GuaType.h"

#include "GLValue.h"


typedef GLValue *(*GLFunctionBuiltinLegacyFunctionPointer)(GuaList *args);


struct _GLFunctionBuiltinLegacy;
typedef struct _GLFunctionBuiltinLegacy GLFunctionBuiltinLegacy;
struct _GLFunctionBuiltinLegacy {
    GuaType _type;
    GLFunctionBuiltinLegacyFunctionPointer function;
};


GLFunctionBuiltinLegacy *
GLFunctionBuiltinLegacyCreate(GLFunctionBuiltinLegacyFunctionPointer function);

int
GLFunctionBuiltinLegacyFree(GLFunctionBuiltinLegacy *f);


#endif /* GLFunctionBuiltinLegacy_h */
