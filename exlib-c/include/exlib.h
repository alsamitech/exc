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

#define ARR_FOREACH(ARRNM, INDEX)\
  for(long unsigned int INDEX=0;INDEX<ARRNM.len ;INDEX++)
#define ifrange(var,least, most) if(var>least&&var<most)
#define dotimes(x, y) for(long unsigned int y=0;y<x;y++)

// Structure Types
typedef struct _Arr arr_t;

extern char** atokl(char* InC, char* delim, long unsigned int* len);

extern unsigned char starts_with(char* _in, char* startsw);

// It is reccomended to use a wrapper to contain what this returns.
char* read_file(char* filenm, long unsigned int* len);
char* get_line(FILE* stream);
arr_t lines_from_file(char* filenm);
  
extern char arr_getbylast(arr_t, long unsigned int);

long unsigned int arr_getbyteinstances(arr_t arr, char byte);

arr_t arr_combinde(arr_t arr1, arr_t arr2);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EXLIB_H
