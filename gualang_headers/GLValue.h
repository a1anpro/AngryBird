#ifndef GLValue_h
#define GLValue_h


#include <stdbool.h>

#include "GuaString.h"
#include "GuaMap.h"

#include "_GLValue.h"
#include "GLValueCreate.h"
#include "GLValueOperators.h"
#include "GLValueType.h"
#include "GLValueInt.h"
#include "GLValueFloat.h"
#include "GLValueObjectBuiltin.h"
// #include "GLValueGuaPyObject.h"
#include "GLValueUserData.h"


#define GLValueInterruptedCheck(value) \
    if (GLValueInterrupted(value)) {   \
        return value;                  \
    }


GLValue *
GLValueCreate(GLValueType type, void *value);

void
GLValueRefIncrease(GLValue *v);

int
GLValueFree(GLValue *v);

int
GLValueFreeWithoutElements(GLValue *v);

GLValueType
GLValueGetType(GLValue *v);

void *
GLValueGetValue(GLValue *v);

GuaString *
GLValueGetTypeString(GLValue *v);

GuaString *
GLValueToString(GLValue *v, bool inStruct);


// 判断是否发生了 Exception, return, break
bool
GLValueInterrupted(GLValue *v);

bool
GLValueInterruptedByException(GLValue *v);


#endif /* GLValue_h */
