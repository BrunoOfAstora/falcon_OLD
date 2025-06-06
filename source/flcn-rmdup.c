								/*flcn-rmdup.c*/
#include "flcn-rmdup.h"
#include "flcn-md5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void rmdup() //add options
{

DIR *ptr_dir;
FILE *ptr_file;

struct dirent *dir;
ptr_dir = opendir(".");

if(ptr_dir)
 {

  while((dir = readdir(ptr_dir)) != NULL)
  {
	if(dir->d_type == DT_REG)
	{
	//add the checking of each file here
	printf("%s\n", dir->d_name);
	}

  }

closedir(ptr_dir);

 }
 else{ perror("Can't open dir"); return; }

return;
}
