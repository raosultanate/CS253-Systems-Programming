#include <stdio.h>
#include <unistd.h>
#include "smash.h"
//#include <String.h>

int showtok(char *bfr);
char *tokenArr[4096];
char path[256];
void executeCommand(char *str)
{

    char *token;
    token = strtok(str, " ");
    char *newbuff = malloc((strlen(str) + 1) * sizeof(char));
    strncpy(newbuff, str, strlen(str) + 1);
    int tokenIndex = 0;
    int number_tok = 0;
    if (token != NULL)
    {
        tokenArr[0] = token;
        tokenIndex++;
        number_tok++;
    }

    if (token == NULL)
    {
        fputs("", stderr);
    }
    else
    {

        while (token != NULL)
        {

            token = strtok(NULL, " "); //iterate
            tokenArr[tokenIndex] = token;
            tokenIndex++;
            number_tok++;
        }

        if ((strcmp(tokenArr[0], "exit") == 0))
        {
            clear_history();
            exit(0);
        }

        else if (strcmp(tokenArr[0], "history") == 0)
        {
            add_history(newbuff, 0);
            print_history();
        }

        else if (strcmp(tokenArr[0], "cd") == 0)
        {

            int change = chdir(tokenArr[1]);

            if (change == 0)
            {
                add_history(newbuff, change);
                printf("%s\n", getcwd(path, 256));
            }

            else
            {
                add_history(newbuff, 1);

                printf("%s: No such file or directory\n", tokenArr[1]);
            }
        }

        else
        {
            add_history(newbuff, 127);
            for (int i = 0; i < number_tok - 1; i++)
            {
                printf("[%d] %s\n", i, tokenArr[i]);
            }
        }
    }
    // look for null case
}