#ifndef GLValueOperators_h
#define GLValueOperators_h


#include "_GLValue.h"


GLValue *
GLValueAdd(GLValue *v1, GLValue *v2);

GLValue *
GLValueSubtract(GLValue *v1, GLValue *v2);

GLValue *
GLValueMultiply(GLValue *v1, GLValue *v2);

GLValue *
GLValueDivide(GLValue *v1, GLValue *v2);

GLValue *
GLValueMod(GLValue *v1, GLValue *v2);

GLValue *
GLValueGreater(GLValue *v1, GLValue *v2);

GLValue *
GLValueLess(GLValue *v1, GLValue *v2);

GLValue *
GLValueEqual(GLValue *v1, GLValue *v2);

GLValue *
GLValueUnequal(GLValue *v1, GLValue *v2);

GLValue *
GLValueGreaterEqual(GLValue *v1, GLValue *v2);

GLValue *
GLValueLessEqual(GLValue *v1, GLValue *v2);

GLValue *
GLValueBitwiseAnd(GLValue *v1, GLValue *v2);

GLValue *
GLValueBitwiseOr(GLValue *v1, GLValue *v2);

GLValue *
GLValueBitwiseXor(GLValue *v1, GLValue *v2);

GLValue *
GLValueBitwiseFlip(GLValue *v1);

GLValue *
GLValueShiftLeft(GLValue *v1, GLValue *v2);

GLValue *
GLValueShiftRight(GLValue *v1, GLValue *v2);

GLValue *
GLValueNegative(GLValue *v1);

GLValue *
GLValueAnd(GLValue *v1, GLValue *v2);

GLValue *
GLValueOr(GLValue *v1, GLValue *v2);

GLValue *
GLValueNot(GLValue *v1);


#endif /* GLValueOperators_h */
