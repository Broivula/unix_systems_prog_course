#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 50 

int main(int argc, char **argv){
  
  if(argc > 1){
    int f_read = open(argv[1], O_RDONLY);
    char buffer[BUFFSIZE];
    int offset = -1;

    while(lseek(f_read, offset, SEEK_END) != -1){
      read(f_read, buffer, 1);
      offset -= 1;
      printf("%c", buffer[0]);
    }
    close(f_read);
  }
  return 0;
}
