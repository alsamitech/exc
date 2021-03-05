#include "include/exlib.h"


char arr_getbylast(arr_t arr, long unsigned int offset){
  return arr.arr[arr.len-offset];
}