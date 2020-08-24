#ifndef GLApply_h
#define GLApply_h


#include "GLValue.h"
#include "GLScope.h"


GLValue *
GLApply(char *code, bool logError);

GLValue *
GLApplyWithScope(char *code, GLScope *scope, bool logError);

GLValue *
GLApplyWithFilePath(char *code, char *filePath, bool logError);

GLValue *
GLApplyWithFilePathAndScope(char *code, char *filePath, GLScope *scope, bool logError, bool freeAll);

GLValue *
GLApplyWithFileContent(char *filePath, bool logError);

GLValue *
GLApplyWithFileContentAndScope(char *filePath, GLScope *scope, bool logError);


#endif /* GLApply_h */
