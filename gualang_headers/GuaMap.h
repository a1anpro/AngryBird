/**
 * @file GuaMap.h
 * @brief GuaMap 接口
 * @details gualang map 对象相关接口
 * @author kuaibiancheng
 */

#ifndef GuaMap_h
#define GuaMap_h


#include <stdbool.h>

#include "GuaList.h"


struct _GuaMap;
typedef struct _GuaMap GuaMap;

/**
* @brief 创建 GuaMap 
*/
GuaMap *
GuaMapCreate(void);

/**
* @brief 将字典中键为 key 的值设置为 value
*/
void
GuaMapSet(GuaMap *m, const char *key, type value);

/**
* @brief 取出字典中键为 key 的值
*/
type
GuaMapGet(GuaMap *m, const char *key);

/**
* @brief 字典的键中是否有 key
*/
bool
GuaMapHas(GuaMap *m, const char *key);

/**
* @brief 删除字典中键为 key 的值
*/
int
GuaMapDelete(GuaMap *m, const char *key);

/**
* @brief 返回字典中所以 keys
*/
GuaList *
GuaMapKeys(GuaMap *m);

/**
* @cond DOXYGEN_EXCLUDE
*/
void
GuaMapClear(GuaMap *m);

int
GuaMapFree(GuaMap *m);

int
GuaMapFreeWithoutElements(GuaMap *m);
/**
* @endcond
*/


#endif /* GuaMap_h */
