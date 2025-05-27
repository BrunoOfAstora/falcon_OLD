#include "flcn-sha256.h"
#include <stdio.h>
#include <string.h>

/* flc-main.c */

int main(int argc, char *argv[])
{
    char *userFileInput = argv[2];
    char *options = argv[1];

    if(argc < 2)
    {
        printf("\nERROR : Less than one argument\n\tUsage => falcon <option> <file> \n\n");
        return 0;
    }

    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        printf("\n> HELP MENU\n\n\n -h or --help \t Help Menu\n\n sha256 \t return sha256 of the file passed\n\n verify \t checks in the database, if the checksum corresponds\n\n\n");
        return 0;
    }

    else if(strcmp(argv[1], "sha256") == 0)
    {
        calculate_hash_256(userFileInput);
        return 0;
    }

    else 
    {
        printf("Invalid option.\n");
        return 0;
    }

return 0;
}

