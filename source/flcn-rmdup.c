								/*flcn-rmdup.c*/
								/*flcn-rmdup.c*/
#include "flcn-rmdup.h"
#include "flcn-sha384.h"

#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct
{
	char hash[97];
	char filename[256];
	UT_hash_handle hh;
} HashEntry;

HashEntry *hash_map = NULL;

void rmdup() //add options(Future idea)
{

	DIR *ptr_dir;
	//FILE *ptr_file;

	struct dirent *dir;
	ptr_dir = opendir(".");

	if (ptr_dir)
	{

		while ((dir = readdir(ptr_dir)) != NULL)
		{
			if (dir->d_type == DT_REG)
			{
				const char *fname = dir->d_name;
				char *hash = calculate_hash_384(fname);

				if (!hash) continue;

				HashEntry *entry;
				HASH_FIND_STR(hash_map, hash, entry);

				if (entry == NULL)
				{
					entry = malloc(sizeof(HashEntry));
					strncpy(entry->hash, hash, 96);
					entry->hash[sizeof(entry->hash) - 1] = '\0';

					strncpy(entry->filename, fname, 256);
					entry->filename[sizeof(entry->filename) - 1] = '\0';
					HASH_ADD_STR(hash_map, hash, entry);
					
				}

				else
				{
					printf("\n  \x1b[31m->Removed:\x1b[0m %s (same: %s)\n", fname, entry->filename);
					remove(fname);
				}

				free(hash);
				//add the checking log of each file here --> OK!
				printf("\nChecking %s...\n", dir->d_name);
			}
		}
		
		closedir(ptr_dir);

		HashEntry *current_entry, *tmp;
		HASH_ITER(hh, hash_map, current_entry, tmp)
		{
			HASH_DEL(hash_map, current_entry);
			free(current_entry);
		}

	}
	else
	{
		perror("Can't open dir");
		return;
	}

	return;
}

