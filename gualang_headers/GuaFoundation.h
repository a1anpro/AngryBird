#ifndef GuaFoundation_h
#define GuaFoundation_h


#include "GuaType.h"


#define not !


struct _GuaStruct;
typedef struct _GuaStruct GuaStruct;
struct _GuaStruct {
    GuaType _type;
};


GuaType
GuaStructGetType(GuaStruct *o);


#endif /* GuaFoundation_h */
