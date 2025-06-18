									/*flcn-verify.c*/

#include "flcn-verify.h"
#include "flcn-sha384.h"

#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512

void verify_hash(const char *userFileInput) // <- Will be modified later to check default dir
{
	bool file_found_flag = false;	
                                        
    char *str_buffer[2],
         *dir_path;

    const char *home;
    struct dirent *dir;

    str_buffer[0] = malloc(MAX);
    str_buffer[1] = malloc(MAX);
    dir_path = malloc(MAX);

    int i, j;
    i = j = 0;  

    char line_buffer[MAX],
         *result,
         *token,
         *state,
         *sha384_result;

    DIR *currDir;
    FILE *cmp_file;
    FILE *original_file;
	
	if(!userFileInput)
	{
		perror("\nFile Not Found, please verify the name.\n");
		return;
	}
	
    sha384_result = calculate_hash_384(userFileInput); // Change to basename() later
	if(!sha384_result) { printf("\n\033[1;31m[ERROR]\033[0m Failed To Calculate SHA384.\n"); return; }

    original_file = fopen(userFileInput, "r");
	if(!original_file) { printf("\n\033[1;31m[ERROR]\033[0m Failed To Open File.\n"); return; }

    home = getenv("HOME");
    if(!home)
    { 
        printf("\n\n'HOME' Directory not found\n\n"); 
        return; 
    }

    snprintf(dir_path, MAX, "%s/%s", home, "flcn-hashes");	

    currDir = opendir(dir_path);

    if (!currDir)
    {
        printf("\n\nCannot open directory: %s\n\n", dir_path);
        return;
    }

    while((dir = readdir(currDir)) != NULL)
    {
        if(dir->d_type == DT_REG)
        {
            const char *cmp_fname = dir->d_name;

            char full_path[MAX];
            snprintf(full_path, MAX, "%s/%s", dir_path, cmp_fname);

            cmp_file = fopen(full_path, "r");
            if (!cmp_file)
            {
                printf("\n\nCannot open file: %s\n\n", full_path);
                continue;
            }
            
            if((result = fgets(line_buffer, MAX, cmp_file)) != NULL)			
                token = strtok_r(result, "/", &state);
            
            i = 0;

            while(token != NULL && i <= 1)
            {
                if(strlen(token) >= MAX)
                {
                    printf("\n\nBuffer Overflow Avoided, the filename is too long.\n\n");
                    fclose(cmp_file);
                    return;
                }

                strcpy(str_buffer[i], token);
                token = strtok_r(NULL, "/", &state);
                i++;
            }

            // Remove o \n do final do hash salvo
            str_buffer[1][strcspn(str_buffer[1], "\n")] = '\0';

            if((strcmp(str_buffer[0], userFileInput) == 0) && (strcmp(str_buffer[1], sha384_result) == 0))
            {
                printf("\n\033[1;32m[OK!]\033[0m File Name match.\n");
                printf("\n\033[1;32m[OK!]\033[0m Hash Checksum match.\n The File is the same and it's intact!\n");
				
				file_found_flag = true;
				closedir(currDir);
    			free(str_buffer[0]);
    			free(str_buffer[1]);
			    free(dir_path);
			    free(sha384_result);
			    fclose(original_file);

				return;
            }

            else if((strcmp(str_buffer[0], userFileInput) != 0) && (strcmp(str_buffer[1], sha384_result) == 0))
            {
				printf("\n\033[1;32m[OK!]\033[0m The File Status is: OK. The file is the same and it's intact.\n");
                printf("\n\033[1;33m[WARNING]\033[0m Hash match but filename differs.\n");
                printf("	File in database: %s | Provided file: %s\n", str_buffer[0], userFileInput);
			
				file_found_flag = true;
				closedir(currDir);
			    free(str_buffer[0]);
			    free(str_buffer[1]);
			    free(dir_path);
			    free(sha384_result);
			    fclose(original_file);

    			return;
            }

            else if((strcmp(str_buffer[0], userFileInput) == 0) && (strcmp(str_buffer[1], sha384_result) != 0))
            {
                printf("\n\033[1;31m[ALERT]\033[0m Filename matches but hash does not.\n");
                printf("	Expected hash: %s | File hash: %s\n", str_buffer[1], sha384_result);
			
				file_found_flag = true;
				closedir(currDir);
			    free(str_buffer[0]);
			    free(str_buffer[1]);
			    free(dir_path);
			    free(sha384_result);
			    fclose(original_file);

			    return;
            }

            else if((strcmp(str_buffer[0], userFileInput) != 0) && (strcmp(str_buffer[1], sha384_result) != 0))
            {
				fclose(cmp_file);
                continue;
				/*printf("\n\033[1;31m[ERROR]\033[0m Both filename and hash differ.\n");
                printf("In database -> Filename: %s | Hash: %s\n", str_buffer[0], str_buffer[1]);
                printf("Provided -> Filename: %s | Hash: %s\n", userFileInput, sha384_result);*/
            }

            fclose(cmp_file);
        }
    }
	
	if((file_found_flag) == false)
		printf("\n\033[1;33m[Notice]\033[0m File Not Found in Database.\n Try the 'save' command, to save the file hash in database\n\n");
	
    closedir(currDir);
    free(str_buffer[0]);
    free(str_buffer[1]);
    free(dir_path);
    free(sha384_result);
    fclose(original_file);

    return;
}



					//Reference Only//
				

 /*
 
    if (!original_file) 
	{
        perror("\nerror in verify function while opening userFileInput\n");
        return;
    }
	
	currDir = opendir(dir_path);
	
    comparasion_file = fopen(savedFilePath, "r");

    if (!comparasion_file) 
	{
        perror("\nerror in verify function while opening the savedFilePath\n");
        return;
    }

    if ((result = fgets(line_buffer, MAX, comparasion_file)) != NULL)
        token = strtok_r(result, "/", &state); //Check the strtok_r documentation

    while (token != NULL && i <= 1) 
	{
		if(strlen(token) >= MAX)
		{
			printf("\nBuffer Overflow Avoided. The string is too long.\n");
			return;
		}

        strcpy(str_buffer[i], token);
        token = strtok_r(NULL, "/", &state);
        i++;
    }

    str_buffer[1][strcspn(str_buffer[1], "\n")] = '\0';

    if ((strcmp(str_buffer[0], userFileInput) == 0 && strcmp(str_buffer[1], sha384_result)) == 0) 
	{
        printf("\n\033[1;32m[OK!]\033[0m File Name match.\n");
        printf("\n\033[1;32m[OK!]\033[0m Hash Checksum match.\n");
    } 
	
	else if ((strcmp(str_buffer[0], userFileInput) == 0 && strcmp(str_buffer[1], sha384_result)) != 0) 
	{
        printf("\n\033[1;32m[OK!]\033[0m File Name match.\n");
        printf("\n\033[1;33m[Warning]\033[0m Checksum Does Not Match!\n");
    }

    else if ((strcmp(str_buffer[1], sha384_result)) != 0) 
	{
        printf("\n\033[1;32m[OK!]\033[0m Hash Checksum match.\n");
    }

	 else
	 {
        printf("\n\033[1;33m[CAUTION]\033[0m Checksum Does Not Mactch!");
     }
	

    return;
}   

*/                                         
