#ifndef GLVariable_h
#define GLVariable_h


#include <stdbool.h>

#include "GLValue.h"


struct _GLVariable;
typedef struct _GLVariable GLVariable;


GLVariable *
GLVariableCreate(GLValue *value, bool constant);

int
GLVariableFree(GLVariable *var);

GLValue *
GLVariableValue(GLVariable *var);

void
GLVariableSetValue(GLVariable *var, GLValue *value);

bool
GLVariableConstant(GLVariable *var);
//
// utils
GLVariable *
GLVariableFromMethod(void *method);

#endif /* GLVariable_h */
