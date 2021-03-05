#include "include/exlib.h"

char** atokl(char* InC, char* delim, long unsigned int* len){
  char** tok=(char**)malloc(2*sizeof(char*));
  //printf("%p\n", tok);

  tok[0]=strtok(strdup(InC), delim);
  {
  int i=1;
  while(tok[i-1]!=NULL){
    tok=(char**)realloc(tok, (i+1)*sizeof(char*));
    tok[i]=strtok(NULL, delim);
    //printf("%p\n", tok[i]);
    i++;
  
  }
  *len=i;
  /*EBRACE*/}
   
  return tok;
}

unsigned char starts_with(char* _in, char* startsw){
  long unsigned int fma=strlen(_in);
  for(unsigned int i=0;i<(fma-1);i++){
    if(_in[i]==0x0||startsw[i]==0x0){
      break;
    }
    if(_in[i]!=startsw[i]){
      return 1;
    }
  }

  return 0;

}