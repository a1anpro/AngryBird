#ifndef GuaArray_h
#define GuaArray_h


struct _GuaArray;
typedef struct _GuaArray GuaArray;
typedef void *type;


GuaArray *
GuaArrayCreate(size_t numOfElements);

size_t
GuaArrayLength(GuaArray *array);

int
GuaArrayFree(GuaArray *array);

type *
GuaArrayData(GuaArray *array);


#endif /* GuaArray_h */
