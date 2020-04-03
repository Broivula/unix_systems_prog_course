#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFFSIZE 50

int main(int argc, char **argv){

  char buff1[BUFFSIZE];
  char buff2[BUFFSIZE];
  int fd_1, fd_2;
  int offset = 0;
  off_t fs1, fs2;

  if(argc > 2){
    if(strcmp(argv[1], argv[2]) == 0){
      printf("can't compare same file!\n");
      return -1;
    }

    fd_1 = open(argv[1], O_RDONLY);
    fd_2 = open(argv[2], O_RDONLY);

    if(fd_1 == -1 && fd_2 == -1){
      printf("ERROR: neither file valid\n");
      return -1;
    }
    else if(fd_1 == -1 || fd_2 == -1){
      printf("ERROR: %s file not valid \n", fd_1 == -1 ? "first" : "second");
      return -1;
    }

    fs1 = lseek(fd_1, 0, SEEK_END);
    fs2 = lseek(fd_2, 0, SEEK_END);

    printf("file size in bytes:\n %s: %d \t %s: %d \n",argv[1], fs1, argv[2], fs2); 

    lseek(fd_1, 0, SEEK_SET);
    lseek(fd_2, 0, SEEK_SET);
    
    while(lseek(fd_1, offset, SEEK_SET) != -1 || lseek(fd_2, offset, SEEK_SET) != -1){
      read(fd_1, buff1, 1);
      read(fd_2, buff2, 1);
      if(buff1[0] != buff2[0]){
        printf("found a different character at position %d \n", offset);
        printf("characters: \"%c\" and \"%c\" \n", buff1[0], buff2[0]);
        return 0;
      }
      offset++;
    }
    printf("given files were identical! \n");
    close(fd_1);
    close(fd_2);

  }

  return 0;
}
