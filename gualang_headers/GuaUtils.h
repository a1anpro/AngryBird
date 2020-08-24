#ifndef GuaUtils_h
#define GuaUtils_h


#include <stdio.h>
#include <stdbool.h>

#include "GuaString.h"
#include "GuaList.h"


#define GuaLog(...)                            \
if (0) {                          \
    printf("DEBUG:" __VA_ARGS__);printf("\n"); \
}
// #define GuaLog(...)


void
ensure(bool condition, const char *message, const char *expect, const char *result);

bool
isNumber(char c);

bool
isNumberHex(char c);

bool
isNumberBin(char c);

bool
isNumberModifier(char c);

bool
isValidNumberString(GuaString *s);

bool
isAlnum(char c);

GuaList *
filenamesFromDirectory(char *path);

char *
dataFromFile(char *path, int *length);

void
writeToFile(const char *content, size_t length, const char *path);

void
appendToFile(const char *content, size_t length, const char *path);

int
randomBetween(int begin, int end);

GuaString *
OSSystemWithOutput(GuaString *cmd);

int
OSGetModifyTime(char *path);

GuaString *
GualangVersion(void);

int
octalFromDecimal(int octal);

char *
directoryFromPath(const char *path);

bool
fileExists(const char *path);

void *
GLCalloc(size_t numOfBlock, size_t sizeOfBlock);

void *
GLMalloc(size_t n);

void
GLFree(void *p);

void *
GLRealloc(void *p, size_t n);

void
printVersion(int argc, char **argv);

//char *
//timeFormated(time_t timestamp);


#endif /* GuaUtils_h */
