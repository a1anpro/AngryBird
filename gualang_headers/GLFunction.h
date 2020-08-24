#ifndef GLFunction_h
#define GLFunction_h


#include "GuaList.h"
#include "GuaType.h"

#include "AST.h"

#include "GLScopeStack.h"
#include "GLObject.h"


enum _GLMethodType {
    GLMethodTypeClass,
    GLMethodTypeInstance,
    GLMethodTypeInstanceTemplate,
    GLMethodTypeInstanceConstructor,
};
typedef enum _GLMethodType GLMethodType;


struct _GLFunction;
typedef struct _GLFunction GLFunction;
struct _GLFunction {
    GuaType _type;
    GuaList *arguments;
    AST *body;
    GLScopeStack *env;
    char *name;
};

struct _GLMethod;
typedef struct _GLMethod GLMethod;
struct _GLMethod {
    GuaType _type;
    GLMethodType type;
    GuaList *arguments;
    AST *body;
    GLScopeStack *env;
    char *name;
    bool isSuper;          // 是否是被 super() 的方式调用的
    GLValue *cls;          // class 关键字能访问到的对象
    GLValue *clsForSuper;  // super 查找时使用的 cls 对象
    GLValue *this;         // this 关键字能访问到的对象
};


GLFunction *
GLFunctionCreate(GuaList *arguments, AST *body, GLScopeStack *env, char *name);

int
GLFunctionFree(GLFunction *f);

GLMethod *
GLMethodCreate(GLMethodType type, GuaList *arguments, AST *body, GLScopeStack *env, bool isSuper, GLValue *cls, GLValue *clsForSuper, GLValue *this, char *name);

int
GLMethodFree(GLMethod *m);


#endif /* GLFunction_h */
