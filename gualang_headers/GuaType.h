#ifndef GuaType_h
#define GuaType_h


enum _GuaType;
typedef enum _GuaType GuaType;
enum _GuaType {
    GuaTypeToken,
    GuaTypeTokenList,
    GuaTypeAST,
    GuaTypeParser,
    GuaTypeInterpreter,
    
    GuaTypeGLValue,
    GuaTypeGLVariable,
    GuaTypeGLScope,
    GuaTypeGLScopeStack,
    GuaTypeGLFunction,
    GuaTypeGLFunctionBuiltin,
    GuaTypeGLFunctionBuiltinLegacy,
    GuaTypeGLMethod,
    GuaTypeGLInterrupt,
    GuaTypeGLObject,
    GuaTypeGLObjectBuiltin,
    
    GuaTypeGuaString,
    GuaTypeGuaList,
    GuaTypeGuaMap,
    GuaTypeGuaArray,
};


#endif /* GuaType_h */
