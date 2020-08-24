#ifndef GLValueInt_h
#define GLValueInt_h


#include "_GLValue.h"


struct _GLValueInt;
typedef struct _GLValueInt GLValueInt;

struct _GLValueBool;
typedef struct _GLValueInt GLValueBool;


GLValueInt *
GLValueCreateInt(int value);

int
GLValueIntValue(GLValue *v);

GuaString *
GLValueIntToString(GLValueInt *v);


GLValueInt *
GLValueCreateBool(bool value);

int
GLValueBoolValue(GLValue *v);

GuaString *
GLValueBoolToString(GLValue *v);


GLValue *
GLValueIntAdd(GLValue *this, GLValue *other);

GLValue *
GLValueIntSubtract(GLValue *this, GLValue *other);

GLValue *
GLValueIntMultiply(GLValue *this, GLValue *other);

GLValue *
GLValueIntDivide(GLValue *this, GLValue *other);

GLValue *
GLValueIntMod(GLValue *this, GLValue *other);

GLValue *
GLValueIntGreater(GLValue *this, GLValue *other);

GLValue *
GLValueIntLess(GLValue *this, GLValue *other);

GLValue *
GLValueIntEqual(GLValue *this, GLValue *other);

GLValue *
GLValueIntUnequal(GLValue *this, GLValue *other);

GLValue *
GLValueIntGreaterEqual(GLValue *this, GLValue *other);

GLValue *
GLValueIntLessEqual(GLValue *this, GLValue *other);

GLValue *
GLValueIntBitwiseAnd(GLValue *this, GLValue *other);

GLValue *
GLValueIntBitwiseOr(GLValue *this, GLValue *other);

GLValue *
GLValueIntBitwiseXor(GLValue *this, GLValue *other);

GLValue *
GLValueIntBitwiseFlip(GLValue *this);

GLValue *
GLValueIntShiftLeft(GLValue *this, GLValue *other);

GLValue *
GLValueIntShiftRight(GLValue *this, GLValue *other);

GLValue *
GLValueIntNegative(GLValue *this);

GLValue *
GLValueIntAnd(GLValue *this, GLValue *other);

GLValue *
GLValueIntOr(GLValue *this, GLValue *other);

GLValue *
GLValueIntNot(GLValue *this);


#endif /* GLValueInt_h */
