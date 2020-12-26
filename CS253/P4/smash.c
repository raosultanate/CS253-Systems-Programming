#include "smash.h"


#define MAXLINE 4096
struct Cmd his[10];

int main(int argc, char **argv)
{

    char bfr[MAXLINE];
    fputs("$ ", stderr); //Output the first prompt
    //Loop reading commands until EOF or error

    init_history();
    while (fgets(bfr, MAXLINE, stdin) != NULL)
    {
        bfr[strlen(bfr) - 1] = '\0'; //Replace newline with NULL
        executeCommand(bfr);
        fputs("$ ", stderr);
    }
    return 0;
}