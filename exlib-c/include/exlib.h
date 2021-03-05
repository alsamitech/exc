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

char** atokl(char* InC, char* delim, long unsigned int* len);

unsigned char starts_with(char* _in, char* startsw);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EXLIB_H