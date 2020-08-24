/**
 * @file GuaList.h
 * @brief GuaList 接口
 * @details gualang list 对象相关接口
 * @author kuaibiancheng
 */
#ifndef __GuaList_H__
#define __GuaList_H__

#include <stdbool.h>
#include <stddef.h>

#include "GuaFoundation.h"


/**
* @cond DOXYGEN_EXCLUDE
*/
struct _GuaNode;
struct _GuaList;
typedef struct _GuaNode GuaNode;
/**
* @endcond
*/
typedef struct _GuaList GuaList;
typedef void *type;

/**
* @brief 创建 GuaList 
*/
GuaList *
GuaListCreate(void);

/**
* @brief 获取 GuaList 长度
*/
size_t
GuaListLength(GuaList *list);

/**
* @cond DOXYGEN_EXCLUDE
*/
int
GuaListFree(GuaList *list);

// 不对 elements 进行 free
int
GuaListFreeWithoutElements(GuaList *list);
/**
* @endcond
*/

/**
* @brief 往数组末尾添加元素
*/
void
GuaListAppend(GuaList *list, type element);

/**
* @brief 往数组开头添加元素
*/
void
GuaListPrepend(GuaList *list, type element);

/**
* @brief 将 l2 合并至 l1
*/
void
GuaListExtend(GuaList *l1, GuaList *l2);

/**
* @brief 获取下标为 index 的元素
*/
type
GuaListElementByIndex(GuaList *list, size_t index);

/**
* @brief 将数组中下标为 index 的值设为 element
*/
void
GuaListSetElementAtIndex(GuaList *list, size_t index, type element);

/**
* @brief 移除下标为 index 的元素
*/
void
GuaListRemoveElementAtIndex(GuaList *list, size_t index);

/**
* @brief l1 和 l2 是否相等
*/
bool
GuaListEquals(GuaList *l1, GuaList *l2);

/**
* @brief 数组中是否有 element
*/
bool
GuaListContains(GuaList *list, type element);


/**
* @cond DOXYGEN_EXCLUDE
*/
GuaNode *
GuaListHead(GuaList *list);

GuaNode *
GuaListTail(GuaList *list);


type
GuaListHeadElement(GuaList *list);

type
GuaListTailElement(GuaList *list);

type
GuaListPopHead(GuaList *list);

type
GuaListPopTail(GuaList *list);
/**
* @endcond
*/

/**
* @brief 复制数组
*/
GuaList *
GuaListCopy(GuaList *list);

/**
* @brief 数组切片, [begin, end)
*/
GuaList *
GuaListCut(GuaList *list, size_t begin, size_t end);

/**
* @cond DOXYGEN_EXCLUDE
*/
void
GuaListLog(GuaList *list);


GuaNode *
GuaNodeNext(GuaNode *node);

GuaNode *
GuaNodePrev(GuaNode *node);

type
GuaNodeElement(GuaNode *node);
/**
* @endcond
*/


#endif
