#include "flcn-save.h"
#include "flcn-md5.h"

#include <stdio.h>

void saveInFile(char *file_name, char *file_hash)
{
char file_name_buffer[128]; //add error handling: test only
char file_hash_buffer[128];

snprintf(file_hash_buffer, sizeof(file_hash_buffer),"%s",file_hash);
snprintf(file_name_buffer, sizeof(file_name_buffer),"%s-hash", file_name); // or argv[1] 


FILE *file;


file = fopen(file_name_buffer, "w");
if(!file){perror("error while opening file"); return;}

fprintf(file, "%s/%s\n", file_name, file_hash);
fclose(file);

return;
}
