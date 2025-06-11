#include "flcn-sha384.h"
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <string.h>

#define BUFFER_FILE 4096

char *calculate_hash_384(const char *userFileInput)
{
size_t size;
FILE *file;

file = fopen(userFileInput, "rb");

if(!file) { perror("\nfopen error\n"); return NULL; }

uint8_t buffer[BUFFER_FILE];
unsigned char md[EVP_MAX_MD_SIZE];
unsigned int leng, i;

EVP_MD_CTX *ctx = EVP_MD_CTX_new();
EVP_DigestInit_ex(ctx, EVP_sha384(), NULL);

while((size = fread(buffer, 1, sizeof(buffer), file)) > 0)
	EVP_DigestUpdate(ctx, buffer, size);

EVP_DigestFinal_ex(ctx, md, &leng);
EVP_MD_CTX_free(ctx);
fclose(file);

char *hex_str = malloc(2 * leng + 1);

if(!hex_str) return NULL;

for(i = 0; i < leng; i++)
	sprintf(&hex_str[i * 2], "%02x", md[i]);

hex_str[2 * leng] = '\0';

return hex_str;
}
