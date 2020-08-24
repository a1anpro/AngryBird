#ifndef GuaString_h
#define GuaString_h


#include <stddef.h>

#include "GuaList.h"


#define _GuaStringMulti(s) #s
#define GuaStringMulti(s) _GuaStringMulti(s)


struct _GuaString;
typedef struct _GuaString GuaString;


GuaString *
GuaStringCreate(const char *s);

GuaString *
GuaStringCreateWithBuffer(char *buffer);

GuaString *
GuaStringCreateByChar(char c);

int
GuaStringFree(GuaString *s);

GuaString *
GuaStringCopy(GuaString *s);

size_t
GuaStringLength(GuaString *s);

size_t
GuaStringEmpty(GuaString *s);

int
GuaStringCharByIndex(GuaString *s, size_t index);

size_t
GuaStringFind(GuaString *s, char *pattern);

bool
GuaStringStartsWith(GuaString *s, char *pattern);

bool
GuaStringStartsWithInRange(GuaString *s, char *pattern, size_t begin, size_t end);

bool
GuaStringEndsWith(GuaString *s, char *pattern);

size_t
GuaStringFindInRange(GuaString *s, char *pattern, size_t begin, size_t end);

int
GuaStringContains(GuaString *s, char *pattern);

int
GuaStringEquals(GuaString *s1, GuaString *s2);

int
GuaStringEqualsChars(GuaString *s1, char *s2);

char *
GuaStringChars(GuaString *s);

GuaString *
GuaStringSlice(GuaString *s, size_t begin, size_t end);

void
GuaStringAppend(GuaString *s1, GuaString *s2);

int
GuaStringFormat(GuaString *s, ...);

int
GuaStringFormatByList(GuaString *s, GuaList *args);

GuaString *
GuaStringFromFloat(float num);

GuaString *
GuaStringFromInt(int num);

GuaString *
GuaStringFromUserData(void *data);

GuaList *
GuaStringSplit(GuaString *s, char *delimiter);

GuaString *
GuaStringStrip(GuaString *s);

GuaString *
GuaStringStripByChar(GuaString *s, char pattern);

GuaString *
GuaStringFromFile(char *path);

void
GuaStringToLower(GuaString *s);


#endif /* GuaString_h */
