											/*flcn-save.c*/

#include "flcn-save.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void saveInFile(char *file_name, char *file_hash)
{

char file_name_buffer[128]; //add error handling: test only
char file_hash_buffer[128];
DIR *dir;
FILE *file;

if(file_name == ".")
 {
	struct sirent *
	
 }

snprintf(file_hash_buffer, sizeof(file_hash_buffer),"%s",file_hash);
snprintf(file_name_buffer, sizeof(file_name_buffer),"%s-hash", file_name); // or argv[1] 

           //add morespecific error cases

file = fopen(file_name_buffer, "w");
if(!file){perror("\nerror while opening file\n"); return;}

fprintf(file, "%s/%s\n", file_name, file_hash);
fclose(file);

return;

}
