#include "flcn-sha256.h"
#include <openssl/sha.h>
#include <stdio.h>
#include <stdint.h>

#define FF fflush(stdout)
#define BUFFER_SHA256 4096
#define BUFFER_FINAL 32

void calculate_hash_256(const char *userFileInput)
{
  int sha256HashInit, sha256HashUpdate, sha256HashFinal, j;

  uint8_t buffer[BUFFER_SHA256];
  uint8_t bufferFinal[BUFFER_FINAL];

  size_t size;	
  FILE *file;
  SHA256_CTX file_hash_state;
  file = fopen(userFileInput, "rb");

  sha256HashInit = SHA256_Init(&file_hash_state);

  while((size = fread(buffer, 1, sizeof(buffer), file)) > 0)
   sha256HashUpdate = SHA256_Update(&file_hash_state, buffer, size);
  
  sha256HashFinal = SHA256_Final(bufferFinal ,&file_hash_state);
  fclose(file);

  printf("\n\nSHA256:  ");
  for(j = 0; j < 32; j++)
  {
   printf("%02x",bufferFinal[j]);
  }

   printf("\n\n");

  return;
}
