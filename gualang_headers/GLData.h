#ifndef GLData_h
#define GLData_h


#include "GuaList.h"
#include "GuaMap.h"

#include "GLValue.h"


GuaMap *
GLDataMethods(void);


GLValue *
GLDataLength(GuaList *args);

GLValue *
GLDataGet(GuaList *args);

GLValue *
GLDataSet(GuaList *args);

GLValue *
GLDataSet(GuaList *args);

GLValue *
GLDataCut(GuaList *args);

GLValue *
GLDataAdd(GuaList *args);

GLValue *
GLDataPop(GuaList *args);

GLValue *
GLDataJoin(GuaList *args);

GLValue *
GLDataRemove(GuaList *args);

GLValue *
GLDataWriteToFile(GuaList *args);

GLValue *
GLDataAppendToFile(GuaList *args);

GLValue *
GLDataToArray(GuaList *args);

GLValue *
GLDataToString(GuaList *args);


// 包几个工具函数来统一处理报错
GLValue *
GLDataListAppend(GuaList *dataList, GLValue *value);

GLValue *
GLDataListSetElementAtIndex(GuaList *dataList, int index, GLValue *value);

GuaList *
GLValuesFromData(char *data, size_t length);

char *
dataFromGLValues(GuaList *GLValues);


#endif /* GLData_h */
