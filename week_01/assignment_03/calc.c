#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int execute_calc(int (*func)(int, int), int x, int y) { return func(x, y); };
int add(int x, int y) { return x+y; };
int subs(int x, int y) { return x-y; };
int divi(int x, int y) { return x/y; };
int mult(int x, int y) { return x*y; };

int main(int argc, char **argv){
  
  int opt;
  if(argc > 1){

    int base = atoi(argv[1]);
    while((opt = getopt(argc, argv, "a:m:s:d:")) != -1){

      static int (*func)(int, int); 
      switch(opt){

        case 'a': func = add;
                  break;
                
        case 's': func = subs;
                  break;

        case 'm': func = mult; 
                  break;

        case 'd': func = divi;
                  break;

        default:  printf("default \n");
                  break;

      }

      base = execute_calc(func, base, atoi(optarg));
    
    }
    printf("result: %d \n", base);
  }
  return 0;
}
