#include "flcn-verify.h"
#include "flcn-verify-all.h"
#include "flcn-sha384.h"

#include <syss/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512

struct Tokens
{
	const char *nameTok;
	char *hashTok;
};


void verify_all(const char *userFileInput, char *savedFilePath)
{
	struct Tokens *tok_ptr;
	struct stat sb;
	struct dirent *dir;
	
	const char *home;

	char *str_buffer[2],
		 dir_path[512];

	DIR *currDir;
	FILE *comparasion_file;

	str_buffer[0] = str_buffer[1] = malloc(MAX);//free

	home = getenv("HOME");
	if(!home){ printf("\n\n'HOME' Not Found\n\n"); return; }
	
	snprintf(dirpath, sizeof(dir_path), "%s/%s", home, "flcn-hashes");

	if(stat(dir_path, &sb) == 0 && S_ISDIR(sb.st_mode)){}

	else
	{
		perror("\n\n The directory dont exist, please run 'falcon save <files>' to create the directory and try again.\n Run 'falcon -h' to see more information\n\n");
		return;
	}
	
	currDir = opendir();
	if(currDir)
	{
		while((dir = readdir(currDir)) != NULL)
		{
			if(dir->d_type == DT_REG)
			{
			 tok_ptr->nameTok = dir->d_name;
			 tok_ptr->hashTok = calculate_hash_384(tok_ptr->nameTok);
	
			 
			}
		}

	}
	

	return;
}
