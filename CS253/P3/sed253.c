//-----------------------------------------------------------------------------
//
// NAME
//  sed253 -- Simplified editor
//
// SYNOPSIS
//  sed253
//  sed253 -s pattern string
//  sed253 -d line1 line2
//
// DESCRIPTION
//  Simplified editor.  Copies lines read from stdin to stdout.  Options:
//
//  -s Substitute every occurrence of pattern with string
//  -d Delete line1 through line2 inclusive
//
// ERRORS
//  Prints usage message and exits abnormally for invalid commands.  Prints an
//  error message and exits abnormally for other issues.
//
// LIMITATIONS
//  Lines of text are limited to a maximum of 1023 chars.
//
// AUTHORS
//  Epoch...................................................................jrc
//
//-----------------------------------------------------------------------------

//Bring in the definitions for our helper functions
#include "copy.h"
#include "delete.h"
#include "substitute.h"
#include <stdio.h>
#include <string.h>

//Initialize the normal (non-error) exit status

//-----------------------------------------------------------------------------
// main -- the main function
//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    char *pattern; //Pointer to the user-supplied pattern
    char *string;
    char *line1;
    char *line2;
    int selectS = 0;
    int selectD = 0;

    //Check for -s option and find the pattern in command-line args
    if (argc == 4)
    {

        if (strcmp(argv[1], "-s") == 0)
        {

            pattern = argv[2]; //Reference to pattern in args
            string = argv[3];  //references to the
            selectS = 1;
            doSubstitute(pattern, string);
            printf("\n");
        }

        else if (strcmp(argv[1], "-d") == 0)
        {
            line1 = argv[2]; //Reference to line1 in args
            line2 = argv[3]; //Reference to line2 in args
            selectD = 1;     //user has selected -d
            doDelete(line1, line2);
            printf("\n");
        }
        else
        {

            fprintf(stderr, "usage: sed253 [-s pattern string] [-d line1 line2]\n");
            return -1;
        }
    }

    else if (argc == 1)
    {
        //Print the content of the file
        doCopy();
        printf("\n");
    }

    else
    {
        fprintf(stderr, "usage: sed253 [-s pattern string] [-d line1 line2]\n");
        return -1;
    }

    return 0;
}
