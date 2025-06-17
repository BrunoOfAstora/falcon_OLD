											/*flcn-save.c*/

#include "flcn-save.h"
#include "flcn-sha384.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void saveInFile(char *file_name, char *file_hash)
{
    char file_name_buffer[128], 
         file_hash_buffer[256],
         full_path[512],
         dir_path[512];

    const char *home;

    DIR *currDir;
    FILE *file;

    struct dirent *dir;

    snprintf(file_hash_buffer, sizeof(file_hash_buffer), "%s", file_hash);
    snprintf(file_name_buffer, sizeof(file_name_buffer), "%s-hash", file_name);

	struct stat sb;

    home = getenv("HOME");
    if (!home) 
	{
        printf("\n\n'HOME' not found\n\n");
        return;
    }

    snprintf(dir_path, sizeof(dir_path), "%s/%s", home, "flcn-hashes");


    if (mkdir(dir_path, 0755) == -1) 
	{
		if(stat(dir_path, &sb) == 0 && S_ISDIR(sb.st_mode)){}

		else 
		{
            perror("\nmkdir error\n");
            return;
        }
    }

    if (strcmp(file_name, ".") == 0) 
	{
        currDir = opendir(".");
        if (currDir) 
		{
            while ((dir = readdir(currDir)) != NULL) 
			{
                if (dir->d_type == DT_REG) 
				{
                    const char *fname = dir->d_name;
                    char *hash = calculate_hash_384(fname);

                    snprintf(full_path, sizeof(full_path), "%s/%s-hash", dir_path, fname);

                    FILE *file_single = fopen(full_path, "w");
                    if (!file_single) 
					{
                        perror("\n\nfopen error\n\n");
                        free(hash);
                        continue;
                    }

                    fprintf(file_single, "%s/%s\n", fname, hash);
					printf("Saving %s hash...\n", fname);
                    fclose(file_single);
                    free(hash);
                }
            }
            closedir(currDir);
			printf("\n\n Done!\n\n");
        }
        return;
    }


    snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, file_name_buffer);

    file = fopen(full_path, "w");
    if (!file) 
	{
        perror("\nerror while opening file\n");
        return;
    }

    fprintf(file, "%s/%s\n", file_name, file_hash);
    fclose(file);

    return;
}

