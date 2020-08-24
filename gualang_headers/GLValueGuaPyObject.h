#ifndef GLValueGuaPyObject_h
#define GLValueGuaPyObject_h


#include "_GLValue.h"
#include "gua_py_object.h"

#include "GuaString.h"


struct _GLValueGuaPyObject;
typedef struct _GLValueGuaPyObject GLValueGuaPyObject;


GLValue *
GLValueFromGuaPyObject(GuaPyObject *o);

GuaPyObject *
GuaPyObjectFromGLValue(GLValue *v);

GuaString *
GLValueGuaPyObjectToString(GLValue *v);


#endif /* GLValueGuaPyObject_h */
