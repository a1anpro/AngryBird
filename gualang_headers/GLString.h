#ifndef GLString_h
#define GLString_h


#include "GuaList.h"
#include "GuaMap.h"

#include "GLValue.h"


GuaMap *
GLStringMethods(void);


GLValue *
GLStringLength(GuaList *args);

GLValue *
GLStringGet(GuaList *args);

GLValue *
GLStringSplit(GuaList *args);

GLValue *
GLStringFind(GuaList *args);

GLValue *
GLStringFormat(GuaList *args);

GLValue *
GLStringCut(GuaList *args);

GLValue *
GLStringReplace(GuaList *args);

GLValue *
GLStringWriteToFile(GuaList *args);

GLValue *
GLStringAppendToFile(GuaList *args);

GLValue *
GLStringToData(GuaList *args);

GLValue *
GLStringToLower(GuaList *args);

GLValue *
GLStringHas(GuaList *args);

GLValue *
GLStringStrip(GuaList *args);

GLValue *
GLStringStartsWith(GuaList *args);

GLValue *
GLStringEndsWith(GuaList *args);


#endif /* GLString_h */
