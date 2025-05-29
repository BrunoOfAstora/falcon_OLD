									/*flcn-md5.c*/
#include "flcn-md5.h"
#include <stdio.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <string.h>

#define BUFFER_FILE 4096

/*i'll do some comments here, as this is the first implementation of EVP*/
char *calculate_md5(const char *userFileInput)
{

size_t size;
FILE *file;
file = fopen(userFileInput, "rb");

if(!file){ perror("fopen"); return NULL; }

uint8_t buffer[BUFFER_FILE]; //file buffer
unsigned char md[EVP_MAX_MD_SIZE]; //MD buffer (buffer final)
unsigned int leng, i;

EVP_MD_CTX *ctx = EVP_MD_CTX_new(); /*<= Store the context of the chosen algorthim(md5 in this case)*/
EVP_DigestInit_ex(ctx, EVP_md5(), NULL); /*initiates the md5 algorithim*/

while((size = fread(buffer, 1, sizeof(buffer), file)) > 0)
 EVP_DigestUpdate(ctx, buffer, size); /*Process the data*/

EVP_DigestFinal_ex(ctx, md, &leng); /*ends and stores the hash*/
EVP_MD_CTX_free(ctx);
fclose(file);

char *hex_str = malloc(2 * leng + 1);

if(!hex_str) return NULL;

for(i = 0; i < leng; i++)
  sprintf(&hex_str[i * 2], "%02x", md[i]);

hex_str[2 * leng] = '\0';

return hex_str;
}
