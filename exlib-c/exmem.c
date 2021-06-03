#include "include/exlib.h"

char* read_file(char* filenm, long unsigned int* len){
  char* buf=0;
  FILE* f=fopen(filenm, "rb");
  if(f){
    fseek(f,0,SEEK_END);
    *len=ftell(f);
    fseek(f,0,SEEK_SET);
    buf=(char*)calloc(1, *len);
    if(buf)
      fread(buf, 1, *len, f);
    fclose(f);
  }
  return buf;

}

char** atokl(char* InC, char* delim, long unsigned int* len){
  long unsigned int capacity=32;
  char** tok=(char**)malloc(capacity*sizeof(char**));
  //printf("%p\n", tok);

  tok[0]=strtok(strdup(InC), delim);
  {
  long unsigned int i=1;
  while(tok[i-1]!=NULL){
    if(i+2>=capacity){
        capacity+=32;
        tok=(char**)realloc(tok, capacity*sizeof(char**));
        if(!tok){
                // something failed
                return 0x0;
        }
    }
    tok[i]=strtok(NULL, delim);
    //printf("%p\n", tok[i]);
    i++;

  }
  *len=i;
  /*EBRACE*/}

  return tok;
}

arr_t lines_from_file(char* filenm){
     arr_t filedata;
     filedata.arr=read_file(filenm, &filedata.len);
     if(!filedata.arr){
            arr_t a={0, 0};
            return a;
     }
     arr_t arr;
     arr.arr=(char*)atokl(filedata.arr, "\n", &arr.len);
     return arr;
}

size_t ptvec_len(void** ptvec){
    size_t len;
    for(len=0;ptvec[len];len++){}
    return len;
}

char* get_line(FILE* stream){
    size_t bytes=0;
    unsigned int capacity=64;
    char* buf=malloc(capacity);
    char c;
#ifdef __unix__
    while((c=fgetc(stream))!=EOF&&c!='\n')
#else
    while((c=fgetc(stream))!=EOF&&c!='\n'&&c!='\r')
#endif // __unix__
    {
        bytes++;
        if(bytes+1>=capacity){
            capacity*=2;
            buf=realloc(buf, capacity);
            if(!buf){
                return 0x0;
            }
        }
        buf[bytes-1]=c;
        
    }
    
    return buf;
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
