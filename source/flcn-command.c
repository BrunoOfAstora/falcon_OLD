#include "flcn-command.h"
#include <string.h>

flcnCommand parse_command(const char *command)
{
  if(strcmp(command, "sha256") == 0) return CMD_SHA256;
  else if(strcmp(command, "md5") == 0) return CMD_MD5;
  else if(strcmp(command, "verify") == 0) return CMD_VERIFY;
  else if(strcmp(command, "shred") == 0) return CMD_SHRED;  
  else if(strcmp(command, "encrypt") == 0) return CMD_ENCRYPT;  
  else if(strcmp(command, "decrypt") == 0) return CMD_DECRYPT;
  else if(strcmp(command, "compare") == 0) return CMD_COMPARE;
  else if(strcmp(command, "--help") == 0 || strcmp(command, "-h") == 0) return CMD_HELP;
  else if(strcmp(command, "sv") == 0) return CMD_SAVE;
  else return CMD_INVALID;

}







