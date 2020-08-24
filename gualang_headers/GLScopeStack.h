#ifndef GLScopeStack_h
#define GLScopeStack_h


#include "GLScope.h"


struct _GLScopeStack;
typedef struct _GLScopeStack GLScopeStack;


GLScopeStack *
GLScopeStackCreate(void);

int
GLScopeStackFree(GLScopeStack *stack);

GLScope *
GLScopeStackTop(GLScopeStack *stack);

void
GLScopeStackPush(GLScopeStack *stack, GLScope *scope);

GLScope *
GLScopeStackPop(GLScopeStack *stack);

GLValue *
GLScopeStackFind(GLScopeStack *stack, char *name);

GLScope *
GLScopeStackFindScope(GLScopeStack *stack, char *name);

GLScopeStack *
GLScopeStackCopy(GLScopeStack *stack);


#endif /* GLScopeStack_h */
