#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int same_file(int, int);

int main(int argc, char **argv){
  if(argc < 3) {  printf("Error: not enough arguments \n"); return(-1); }

  same_file(open(argv[1], O_RDONLY), open(argv[2], O_RDONLY)) == TRUE ? printf("same files \n") : printf("not the same files \n");
  return 0;
}

int same_file(int fd1, int fd2){
  
  if(fd1 == -1 || fd2 == -1){
    printf("Error: please provide valid files.\n");
    exit(-1);
  }

  struct stat f_info1;
  struct stat f_info2;
  fstat(fd1, &f_info1);
  fstat(fd2, &f_info2);

  printf("file1 ino: %d \n", f_info1.st_ino);
  printf("file2 ino: %d \n", f_info2.st_ino);

  printf("file1 dev_t: %d \n", f_info1.st_dev);
  printf("file2 dev_t: %d \n", f_info2.st_dev);
  
  printf("file1 special dev_t: %d \n", f_info1.st_rdev);
  printf("file2 special dev_t: %d \n", f_info2.st_rdev);

  return (f_info1.st_dev == f_info2.st_dev) && (f_info1.st_ino == f_info2.st_ino);
}
