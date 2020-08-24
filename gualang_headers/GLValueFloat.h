#ifndef GLValueFloat_h
#define GLValueFloat_h


#include "_GLValue.h"


struct _GLValueFloat;
typedef struct _GLValueFloat GLValueFloat;


GLValueFloat *
GLValueCreateFloat(float value);

float
GLValueFloatValue(GLValue *v);

GuaString *
GLValueFloatToString(GLValueFloat *v);

GLValue *
GLValueFloatAdd(GLValue *this, GLValue *other);

GLValue *
GLValueFloatSubtract(GLValue *this, GLValue *other);

GLValue *
GLValueFloatMultiply(GLValue *this, GLValue *other);

GLValue *
GLValueFloatDivide(GLValue *this, GLValue *other);

GLValue *
GLValueFloatMod(GLValue *this, GLValue *other);

GLValue *
GLValueFloatGreater(GLValue *this, GLValue *other);

GLValue *
GLValueFloatLess(GLValue *this, GLValue *other);

GLValue *
GLValueFloatEqual(GLValue *this, GLValue *other);

GLValue *
GLValueFloatUnequal(GLValue *this, GLValue *other);

GLValue *
GLValueFloatGreaterEqual(GLValue *this, GLValue *other);

GLValue *
GLValueFloatLessEqual(GLValue *this, GLValue *other);

GLValue *
GLValueFloatNegative(GLValue *this);

GLValue *
GLValueFloatAnd(GLValue *this, GLValue *other);

GLValue *
GLValueFloatOr(GLValue *this, GLValue *other);

GLValue *
GLValueFloatNot(GLValue *this);


#endif /* GLValueFloat_h */
