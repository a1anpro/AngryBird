#ifndef GLValueObjectBuiltin_h
#define GLValueObjectBuiltin_h


#include "_GLValue.h"


typedef enum _GLObjectBuiltinType GLObjectBuiltinType;


GLValue *
GLValueCreateBuiltinObjectString(GuaString *string);

GLValue *
GLValueCreateBuiltinObjectMap(GuaMap *map);

GLValue *
GLValueCreateBuiltinObjectArray(GuaList *array);

GLValue *
GLValueCreateBuiltinObjectData(GuaList *data);

void *
GLValueObjectBuiltinGetValue(GLValue *v);

GLObjectBuiltinType
GLValueObjectBuiltinGetType(GLValue *v);

GLValue *
GLValueObjectBuiltinAdd(GLValue *v1, GLValue *v2);

GLValue *
GLValueObjectBuiltinEqual(GLValue *v1, GLValue *v2);

GLValue *
GLValueObjectBuiltinUnequal(GLValue *v1, GLValue *v2);


#endif /* GLValueObjectBuiltin_h */
