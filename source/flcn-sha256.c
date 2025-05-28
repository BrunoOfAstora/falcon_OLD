/*flcn-sha256.c*/
#include "flcn-sha256.h"
#include <openssl/evp.h>
#include <stdio.h>
#include <stdint.h>

#define BUFFER_FILE 4096

/*>Now updated to EVP<*/

void calculate_hash_256(const char *userFileInput)
{
  size_t size;	
  FILE *file;
  file = fopen(userFileInput, "rb");
  if(!file){ perror("fopen"); return;}

  uint8_t buffer[BUFFER_FILE];
  unsigned char md_buffer[EVP_MAX_MD_SIZE];  // digest
  unsigned int leng, j;

  EVP_MD_CTX *ctx = EVP_MD_CTX_new();
  EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);

  while((size = fread(buffer, 1, sizeof(buffer), file)) > 0)
   EVP_DigestUpdate(ctx, buffer, size);
  
  EVP_DigestFinal_ex(ctx, md_buffer, &leng);

  EVP_MD_CTX_free(ctx);

  fclose(file);

  printf("\n\nSHA256:  ");
  for(j = 0; j < 32; j++)
  {
   printf("%02x",md_buffer[j]);
  }

   printf("\n\n");

  return;
}
