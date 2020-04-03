#include <stdio.h>

int main(int argc, char **argv)
{
  if(argc > 1){
    int i;
    printf("amount of arguments: %d\n", argc-1);
    for(i = 1; i < argc; i++){
      printf("argument[%d] = %s\n", i, argv[i]);
    }
  }else{
    printf("no arguments given \n");
    return 1;
  }
  return 0;
}
