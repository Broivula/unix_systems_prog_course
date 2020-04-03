#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
  
  if(argc < 3){
    printf("Error: not enough arguments given \n");
    exit(-1);
  }
  
  DIR *dir1, *dir2;

  dir1 = opendir(argv[1]);
  dir2 = opendir(argv[2]);

  struct dirent *dir1_contents, *dir2_contents;

  while(dir1_contents = readdir(dir1)){
    char *f_name = dir1_contents->d_name;
    while(dir2_contents = readdir(dir2)){
      if(strcmp(f_name, dir2_contents->d_name) == 0 && strcmp(f_name, ".") != 0 && strcmp(f_name, "..") != 0){
        printf("%s was found in both directories. \n", f_name);
      }
    }
   rewinddir(dir2);
  }

  return 0;
  
}
