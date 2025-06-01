									/*flcn-verify.c*/

#include "flcn-verify.h"
#include "flcn-md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 255
#define MAX_LINE_CHAR 128

void verify_hash(const char *userFileInput, char *saveFilePath)
{    					//<= Change return =>\\
FILE *saveFile
int buffer[BUFFER];
int i, maxLineChar;
char *str_ptr[2];
char *hash_md5;
maxLineChar = MAX_LINE_CHAR;

						//<= add error handling =>\\

if(userFileInput == NULL)
{
 printf("can't open the file | verify.c error");
 return;
}

hash_md5 = calculate_md5(userInputFile);
saveFile = fopen(saveFilePath, "r");


while(fgets(buffer, maxLineChar, saveFile) != NULL) //do a split, w/ the "/" being the divider,
{
                                                     // then store each side on an array.
  if()
}

//this loop must check if the array in the first index matches with the user input file
//if so, then check if the second index (after the split), matches the checksum that will 
//be generated again at runtime

fclose(saveFile);
return;
} 


