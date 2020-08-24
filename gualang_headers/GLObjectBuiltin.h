#ifndef GLObjectBuiltin_h
#define GLObjectBuiltin_h


#include "GLValue.h"
#include "GuaMap.h"
#include "GuaString.h"


enum _GLObjectBuiltinType;
typedef enum _GLObjectBuiltinType GLObjectBuiltinType;
enum _GLObjectBuiltinType {
    GLObjectBuiltinTypeString,
    GLObjectBuiltinTypeArray,
    GLObjectBuiltinTypeData,
    GLObjectBuiltinTypeMap,
};


struct _GLObjectBuiltin;
typedef struct _GLObjectBuiltin GLObjectBuiltin;


GLObjectBuiltin *
GLObjectBuiltinCreate(GLObjectBuiltinType type, void *value, GuaMap *methods);

int
GLObjectBuiltinFree(GLObjectBuiltin *obj);

void *
GLObjectBuiltinGetValue(GLObjectBuiltin *obj);

GLObjectBuiltinType
GLObjectBuiltinGetType(GLObjectBuiltin *obj);

GuaMap *
GLObjectBuiltinGetMethods(GLObjectBuiltin *obj);

bool
GLObjectBuiltinHasAttr(GLObjectBuiltin *obj, const char *name);

GLValue *
GLObjectBuiltinGetAttr(GLObjectBuiltin *obj, const char *name);

GuaString *
GLObjectBuiltinToString(GLObjectBuiltin *obj, bool inStruct);


#endif /* GLObjectBuiltin_h */
