#include "exlib-c/include/exlib.h"

/*Test File*/

int main(void) {
    arr_t arr1;
    arr1.len=4; 
    char n[]={1, 2, 3, 4};
    arr1.arr=n;
    arr_t arr2;
    arr2.len=4;
    char ice[]={5, 6, 7, 8};
    arr_t nice=arr_combinde(arr1, arr2);
    printf("\033[1;31m%lu and %u\033[0m\n", nice.len, *(nice.arr+4));
    ARR_FOREACH(arr1, i){
      printf("%d, %lu\n", arr1.arr[i], i);
    }
  return 0;
}