#ifndef GLScopeGlobal_h
#define GLScopeGlobal_h


#include "GLScope.h"


void
GLScopeGlobalSetArgs(int argc, char **argv);

// 创建 os.importPaths 数组，设置到 global 里
void
GLScopeGlobalImportPathsSet(void);

// 往 os.importPaths 数组里加元素
void
GLScopeGlobalImportPathsAppend(char *path);

// 获取 os.importPaths 数组
GuaList *
GLScopeGlobalImportPathsGet(void);

GLScope *
GLScopeGlobalGet(void);


#endif /* GLScopeGlobal_h */
