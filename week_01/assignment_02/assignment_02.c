#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv){
  
  if(argc > 1){
    char *env;
    char var[250] = "";
    env = getenv(argv[1]);
    if(env != NULL){
      strncpy(var, env, 250);
      printf("%s \n", var);
    }else{
      extern char **environ;
      char new_val[50];
      sprintf(new_val,"%s=NOT_SET", argv[1]);
      printf("no environment variable of that name found \n");
     // putenv("TESTI=KIKEL");
      
      if(putenv(new_val) != 0){
        printf("error setting new value \n");
        return -1;
      }
      
      printf("..value set!\n");
      char **ptr = environ;
      while(&(**ptr) != NULL){
        printf("%s \n", *ptr);
        ++ptr;
      }
      return 0;
    }
  }else{
    printf("no argument given \n");
    return -1;
  }
  
  return 0;
}
