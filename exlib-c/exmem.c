#include "include/exlib.h"

char* read_file(const char* const filenm, long unsigned int* len){
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

char** atokl(const char* const InC, const char* const delim, long unsigned int* len){
	// eight as that provides room for small splitting operations
  long unsigned int capacity=8;
  char** tok=(char**)malloc(capacity*sizeof(char**));
	if(!tok)return 0x0;

  tok[0]=strtok(strdup(InC), delim);
  {
  long unsigned int i=1;
  while(tok[i-1]!=NULL){
    if(i+2>=capacity){
        capacity*=2;
        tok=(char**)realloc(tok, capacity*sizeof(char**));
        if(!tok){
          // something failed
					free(tok[0]);
					free(tok);
          return 0x0;
        }
    }
    tok[i++]=strtok(NULL, delim);

  }
  *len=i;
  /*EBRACE*/}

  return tok;
}

arr_t lines_from_file(const char* const filenm){
     arr_t filedata;
     filedata.arr=read_file(filenm, &filedata.len);
     if(!filedata.arr)
            return filedata;
     
     arr_t arr;
     arr.arr=(char*)atokl(filedata.arr, "\n", &arr.len);
     return arr;
}

size_t ptvec_len(const void** const ptvec){
    size_t len=0;
    while(ptvec[len++]);
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
            if(!buf)
                return 0x0;
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
