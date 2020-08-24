#ifndef GLLibrary_h
#define GLLibrary_h


#include "GuaString.h"
#include "GuaList.h"
#include "GuaInterpreter.h"

#include "GLValue.h"


// args 是 GLValue * 的 list
GLValue *
GLLog(GuaList *args);

GLValue *
GLLogDebug(GuaList *args);

GLValue *
GLStringFromFile(GuaList *args);

GLValue *
GLDataFromFile(GuaList *args);

GLValue *
GLEnsure(GuaList *args);

GLValue *
GLImport(GuaList *args);

GLValue *
GLType(GuaList *args);

GLValue *
GLEnsureError(GuaList *args);

GLValue *
GLVersion(GuaList *args);

GLValue *
GLJsonLoads(GuaList *args);
//
// math
GLValue *
GLMathRound(GuaList *args);

GLValue *
GLMathSin(GuaList *args);

GLValue *
GLMathCos(GuaList *args);

GLValue *
GLMathRandomBetween(GuaList *args);
//
// os
GLValue *
GLOSSystem(GuaList *args);

GLValue *
GLOSSystemWithOutput(GuaList *args);

GLValue *
GLOSGetModifyTime(GuaList *args);

GLValue *
GLInput(GuaList *args);


#endif /* GLLog_h */
