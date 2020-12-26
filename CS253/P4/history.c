#include "history.h"

struct Cmd *his[MAXHISTORY]; //declaration of pointer array for struct type struct Cmd
int addCounter = 0;
int sequenceNumber = 1;

//Builds data structures for recording cmd history
void init_history(void)
{
    for (int i = 0; i < MAXHISTORY; i++)
    {
        his[i] = malloc(sizeof(struct Cmd));
        his[i]->cmd = NULL;
        his[i]->exitStatus = 0;
    }
}
//Adds an entry to the history
void add_history(char *cmd, int exitStatus)
{

    if (addCounter >= MAXHISTORY)
    {

        free(his[0]);
        his[0] = malloc(sizeof(struct Cmd));
        for (int i = 0; i < MAXHISTORY; i++)
        {
            his[i] = his[i + 1];
        }
        sequenceNumber++;
        his[9] = malloc(sizeof(struct Cmd));
        his[MAXHISTORY - 1]->cmd = cmd;
        his[MAXHISTORY - 1]->exitStatus = exitStatus;
    }
    else
    {
        his[addCounter]->cmd = cmd;
        his[addCounter]->exitStatus = exitStatus;
        addCounter = addCounter + 1;
    }
}
//Frees all malloc’d memory in the history
void clear_history(void)
{
    for (int i = 0; i < MAXHISTORY; i++)
    {
        free(his[i]);
    }
}
//Prints the history to stdout
void print_history(void)
{

    for (int i = 0; i < MAXHISTORY; i++)
    {
        printf("%d [%d] %s\n", sequenceNumber + i, his[i]->exitStatus, his[i]->cmd);
    }
}