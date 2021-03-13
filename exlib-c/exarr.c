#include "include/exlib.h"


char arr_getbylast(arr_t arr, long unsigned int offset){
  return arr.arr[arr.len-offset];
}

long unsigned int arr_getbyteinstances(arr_t arr, char byte){
  long unsigned int inst=0;
  for(long unsigned int i=0;i<arr.len; i++){
      if(arr.arr[i]==byte) inst++;
  }
  return inst;
}

arr_t arr_combinde(arr_t arr1, arr_t arr2){
  arr_t arr;
  arr.len=arr1.len+arr2.len;
  arr.arr=malloc(arr.len);
  memcpy(arr.arr, arr1.arr, arr1.len);
  memcpy(arr.arr+arr1.len, arr2.arr, arr2.len);
  return arr;
}