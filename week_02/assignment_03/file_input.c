#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define PERMISSIONS S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH
#define BUFFSIZE 50 

int main(int argc, char **argv){

  char c;
  char buffer[BUFFSIZE];
  int c_counter = 0;  

  if(argc < 2){ printf("ERROR: not enough arguments given\n"); return -1;}
  
  int new_file = open(argv[1], O_CREAT | O_WRONLY, PERMISSIONS);
 
  while(read(0, &c, 1) != -1){
    buffer[c_counter] = c;
    c_counter++;
    if(c == '\n'){
     buffer[c_counter] = '\n';
     write(new_file, buffer, c_counter);
     c_counter = 0;
    }
  }
  return 0;
}
