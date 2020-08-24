#ifndef GLValueType_h
#define GLValueType_h


#include "_GLValue.h"


GLValue *
GLValueCreateType(GuaString *typeString);

GuaString *
logFromTypeString(GuaString *typeString);

GuaString *
GLValueTypeToString(GLValue *value);

GLValue *
GLValueTypeEqual(GLValue *v1, GLValue *v2);

GLValue *
GLValueTypeUnequal(GLValue *v1, GLValue *v2);


#endif /* GLValueType_h */
