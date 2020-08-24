#ifndef GLValueCreate_h
#define GLValueCreate_h


#include "GuaString.h"

#include "_GLValue.h"


GLValue *
GLValueCreateNull(void);

GLValue *
GLValueCreateUndefined(void);

GLValue *
GLValueCreateException(GuaString *message);

GLValue *
GLValueCreateReturn(GLValue *v);

GLValue *
GLValueCreateBreak(void);

GLValue *
GLValueCreateContinue(void);

GLValue *
GLValueCreateObject(void);

GLValue *
GLValueCreateString(GuaString *string);


#endif /* GLValueCreate_h */
