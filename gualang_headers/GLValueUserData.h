#ifndef GLValueUserData_h
#define GLValueUserData_h

#include "_GLValue.h"


struct _GLValueUserData;
typedef struct _GLValueUserData GLValueUserData;


GLValueUserData *
GLValueCreateUserData(void *value);

void *
GLValueUserDataValue(GLValue *v);


#endif /* GLValueUserData_h */
