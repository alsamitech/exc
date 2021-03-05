#ifndef EXLIB_H
#define EXLIB_H

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Structures
struct _Arr{
  char* arr;
  long unsigned int len;
};

// Structure Types
typedef struct _Arr arr_t;

extern char** atokl(char* InC, char* delim, long unsigned int* len);

extern unsigned char starts_with(char* _in, char* startsw);

extern char arr_getbylast(arr_t, long unsigned int);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EXLIB_H