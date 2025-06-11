/*flcn-command.h*/

#ifndef FLCN_COMMAND_H
#define FLCN_COMMAND_H

typedef enum
{
	CMD_INVALID,
	CMD_SHA256,
	CMD_SHA384,
	CMD_MD5,
	CMD_VERIFY,
	CMD_SHRED,
	CMD_COMPRESS,
	CMD_ENCRYPT,
	CMD_DECRYPT,
	CMD_COMPARE,
	CMD_HELP,
	CMD_SAVE,
	CMD_RMDUP

}flcnCommand;

flcnCommand parse_command(const char *command);

#endif
