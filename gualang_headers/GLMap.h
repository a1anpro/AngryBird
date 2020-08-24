#ifndef GLMap_h
#define GLMap_h


#include "GuaList.h"
#include "GuaMap.h"

#include "GLValue.h"


GuaMap *
GLMapMethods(void);


GLValue *
GLMapGet(GuaList *args);

GLValue *
GLMapGetWithoutDefault(GuaList *args);

GLValue *
GLMapSet(GuaList *args);

GLValue *
GLMapDelete(GuaList *args);

GLValue *
GLMapKeys(GuaList *args);

GLValue *
GLMapLength(GuaList *args);

GLValue *
GLMapHas(GuaList *args);


#endif /* GLMap_h */
