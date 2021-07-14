#ifndef EXLIB_H
#define EXLIB_H

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

// Structures
struct _Arr{
  char* arr;
  long unsigned int len;
};

#define ARR_FOREACH(ARRNM, INDEX)\
  for(long unsigned int INDEX=0;INDEX<ARRNM.len ;INDEX++)
#define ifrange(var,least, most) if(var>least&&var<most)
#define iferange(var,least, most) if(var>=least&&var<=most)
#define dotimes(x, y) for(long unsigned int y=0;y<x;y++)
#define s_foreach(str, index) for(size_t index=0;str[index];index++)

// Structure Types
typedef struct _Arr arr_t;

// It is reccomended to use a wrapper to contain what this returns. (arr_t)
char* read_file(const char* const filenm, long unsigned int* len);
char* get_line(FILE* stream);
arr_t lines_from_file(const char* const filenm);
  
#define arr_getbylast(arr,offset) arr.arr[arr.len-offset]

long unsigned int arr_getbyteinstances(const arr_t arr,const char byte);

arr_t arr_combinde(arr_t arr1, arr_t arr2);
  
size_t ptvec_len(const void** const ptvec);

extern char** atokl(const char* const InC,const char* const delim, long unsigned int* len);

extern unsigned char starts_with(char* _in, char* startsw);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EXLIB_H
