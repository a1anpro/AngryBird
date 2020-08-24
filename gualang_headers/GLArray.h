#ifndef GLArray_h
#define GLArray_h


#include "GuaList.h"
#include "GuaMap.h"

#include "GLValue.h"


GuaMap *
GLArrayMethods(void);


GLValue *
GLArrayLength(GuaList *args);

GLValue *
GLArrayGet(GuaList *args);

GLValue *
GLArraySet(GuaList *args);

GLValue *
GLArraySet(GuaList *args);

GLValue *
GLArrayCut(GuaList *args);

GLValue *
GLArrayAdd(GuaList *args);

GLValue *
GLArrayExtend(GuaList *args);

GLValue *
GLArrayPop(GuaList *args);

GLValue *
GLArrayJoin(GuaList *args);

GLValue *
GLArrayRemove(GuaList *args);

GLValue *
GLArrayToData(GuaList *args);


#endif /* GLArray_h */
