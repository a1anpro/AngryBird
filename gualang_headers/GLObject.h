#ifndef GLObject_h
#define GLObject_h


#include <stdbool.h>

#include "GuaList.h"

#include "GLValue.h"
#include "GLVariable.h"


struct _GLObject;
typedef struct _GLObject GLObject;


GLObject *
GLObjectCreate(void);

void
GLObjectSet(GLObject *object, const char *name, GLVariable *variable);

bool
GLObjectHas(GLObject *object, const char *name);

GLVariable *
GLObjectGet(GLObject *object, const char *name);

GuaList *
GLObjectKeys(GLObject *object);

int
GLObjectFree(GLObject *object);

GuaString *
GLObjectToString(GLObject *object);


#endif /* GLObject_h */
