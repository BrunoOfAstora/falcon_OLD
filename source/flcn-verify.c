									/*flcn-verify.c*/

#include "flcn-verify.h"
#include "flcn-sha384.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

void verify_hash(const char *userFileInput, char *savedFilePath)
{    						// OK! \\ remaking the function in the right way.(i think...); 

char *str_buffer[2]; //The new string will store the copy of file name and hash of "savedPathFile"
str_buffer[0] = malloc(MAX);;
str_buffer[1] = malloc(MAX);

int i, j;	//iterators
i = j = 0;  //i

char line_buffer[MAX], 
	 *result,
	 *token, 
	 *state, 
	 *sha384_result;

FILE *comparasion_file;
FILE *original_file;

sha384_result = calculate_hash_384(userFileInput);

original_file = fopen(userFileInput, "r");
if(!original_file) { perror("\nerror in verify function while opening userFileInput\n"); return; }

comparasion_file = fopen(savedFilePath, "r");
if(!comparasion_file) { perror("\nerror in verify function while opening the savedFilePath\n"); return; }

if((result = fgets(line_buffer, MAX, comparasion_file)) != NULL)
	token = strtok_r(result, "/", &state); //Check the strtok_r documentation

while(token != NULL && i <= 2)
 {
  strcpy(str_buffer[i], token);
  token = strtok_r(NULL, "/", &state);
  i++;
 }

str_buffer[1][strcspn(str_buffer[1], "\n")] = '\0';

if((strcmp(str_buffer[0], userFileInput)) == 0) { printf("\n\033[1;32m[OK!]\033[0m File Name match.\n"); }
	else{ printf("\n\033[1;33m[Warning]\033[0m File Name Does Not Match!\n"); }

if((strcmp(str_buffer[1], sha384_result)) == 0) { printf("\n\033[1;32m[OK!]\033[0m Hash Checksum match.\n"); }
	else{ printf("\n\033[1;33m[CAUTION]\033[0m Checksum Does Not Mactch!"); }

return;

}                                                  
