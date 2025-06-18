#include "flcn-sha256.h"
#include "flcn-md5.h"
#include "flcn-command.h"
#include "flcn-save.h"
#include "flcn-verify.h"
#include "flcn-rmdup.h"
#include "flcn-sha384.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 128
/* flc-main.c */

void print_help()
{
    printf("\n>>Help Menu\n\n Usage => falcon <option> <file>\n\n Functions:\n  sha256 \t Calculates the SHA256 of the file\n  md5 \t\t Return the hash MD5 of the file\n More Functions will be added soon \n\n");
    return;
}

int main(int argc, char *argv[])
{
    const char *opt = "";

    if (argc < 2)
    {
        printf("\nERROR : Less than one argument\n\n\tUsage => falcon <option> <file> \n\n");
        return 0;
    }

    char *save_384;
    char *hash_md5;
    char *userFileInput = argv[2];
    char *options = argv[1];
    flcnCommand cmd;

    cmd = parse_command(options);

    switch (cmd)
    {
    case CMD_HELP:
        print_help();
        break;



    case CMD_SHA256: // SHA256
        if (argc != 3)
        {
            printf("\n\n The sha256 command should receive one and only one argument(file) \n\n");
            break;
        }
        calculate_hash_256(userFileInput);
        break;



    case CMD_MD5: // MD5
        if (argc != 3)
        {
            printf("\n\n The MD5 command should receive one and only one argument(file)");
            break;
        }
        hash_md5 = calculate_md5(userFileInput);
        printf("\n\nMD5: %s\n\n", hash_md5);
        free(hash_md5);
        break;



    case CMD_SAVE: // Save to File
        if (argc != 3)
        {
            printf("\n\n Need to specify the file, use 'falcon -h' for help.\n\n");
            break;
        }
        save_384 = calculate_hash_384(userFileInput);
        saveInFile(userFileInput, save_384);
        free(save_384);
        break;



    case CMD_VERIFY:
        if (argc != 4)
        {
            printf("\n\nNeed to specify the file, use 'falcon -h' for help.");
            break;
        }
        verify_hash(userFileInput, argv[3]);
        break;



    case CMD_RMDUP:
        if (argc != 2)
        {
            printf("\n\nErrormdg_rmdup\n\n");
            break;
        }
        rmdup();
        break;



    case CMD_SHA384:
        if (argc != 3)
        {
            printf("\n\nYour need to specfy the file, use 'falcon -h' for help\n\n");
            break;
        }
        char *sha384 = calculate_hash_384(userFileInput);
        printf("\n\nSHA384: %s\n\n", sha384);
        break;



    default:
        printf("invalid command, try 'falcon -h' for help\n");
        break;
    }

    return 0;
}

