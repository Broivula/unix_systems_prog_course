#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int search(int, char*, char*);

int main(int argc, char **argv){
  
  int i, result;

  if(argc < 3){
    printf("Error: not enough arguments given \n");
    exit(-1);
  }
  
  for(i = 2; i < argc; i++){
    result = search(open(argv[i], O_RDONLY), argv[1], argv[i]); 
    printf("%25s: \t", argv[i]);
    result == TRUE ? printf("yes\n") : printf("no\n");
  }
  

  return 0;
}

int search(int fd, char *string, char *fname){

  if(fd == -1){
    printf("Error: %s is not a valid file\n", fname);
    exit(-1);
  }

  char *buf;

  off_t f_size = lseek(fd, 0, SEEK_END);
  buf = malloc((f_size + 1) * sizeof(char));
  buf[f_size] = '\0';
  
  lseek(fd, 0, SEEK_SET);

  pread(fd, buf, f_size, 0);

  return strstr(buf, string) == NULL ? FALSE : TRUE;
}
