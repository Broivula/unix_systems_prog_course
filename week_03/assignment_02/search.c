#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int search(int, char*);

int main(int argc, char **argv){
  
  if(argc < 3){
    printf("Error: not enough arguments given \n");
    exit(-1);
  }
  
  search(open(argv[1], O_RDONLY), argv[2]) == TRUE ? printf("found given string in the file!\n") : printf("given string was not found in the file.\n");

  return 0;
}

int search(int fd, char *string){
  char *buf;

  off_t f_size = lseek(fd, 0, SEEK_END);
  buf = malloc((f_size + 1) * sizeof(char));
  buf[f_size] = '\0';
  
  lseek(fd, 0, SEEK_SET);

  pread(fd, buf, f_size, 0);

  return strstr(buf, string) == NULL ? FALSE : TRUE;
}
