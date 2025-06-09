								/*flcn-rmdup.c*/
#include "flcn-rmdup.h"
#include "flcn-md5.h"

#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct
{
  char hash[33];
  char filename[256];
  UT_hash_handle hh;
} HashEntry;

HashEntry *hash_map = NULL;

void rmdup() //add options
{

DIR *ptr_dir;
//FILE *ptr_file;

struct dirent *dir;
ptr_dir = opendir(".");

if(ptr_dir)
 {

  while((dir = readdir(ptr_dir)) != NULL)
  {
	if(dir->d_type == DT_REG)
	{
	 const char *fname = dir->d_name;
	 char *hash = calculate_md5(fname);

	 if(!hash) continue;
	 
	 HashEntry *entry;
	 HASH_FIND_STR(hash_map, hash, entry);

	 if (entry == NULL)
	 {
	  entry = malloc(sizeof(HashEntry));
	  strncpy(entry->hash, hash, 32);
	  entry->hash[32] = '\0';

	  strncpy(entry->filename, fname, 256);
	  HASH_ADD_STR(hash_map, hash, entry);
	 } 
	 else
	 {
	  printf("\nDuplicated: %s (same: %s)\n", fname, entry->filename);
	  remove(fname);
	
	 }
	 free(hash);
	//add the checking of each file here
	printf("%s\n", dir->d_name);
	}

  }

closedir(ptr_dir);

 }
 else{ perror("Can't open dir"); return; }

return;
}
