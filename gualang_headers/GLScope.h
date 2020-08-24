#ifndef GLScope_h
#define GLScope_h


#include <stdbool.h>

#include "GuaList.h"

#include "GLValue.h"
#include "GLVariable.h"


struct _GLScope;
typedef struct _GLScope GLScope;


GLScope *
GLScopeCreate(void);

void
GLScopeSet(GLScope *scope, const char *name, GLVariable *variable);

bool
GLScopeHas(GLScope *scope, const char *name);

GLVariable *
GLScopeGet(GLScope *scope, const char *name);

GuaList *
GLSCopeKeys(GLScope *scope);

int
GLScopeFree(GLScope *scope);


#endif /* GLScope_h */
