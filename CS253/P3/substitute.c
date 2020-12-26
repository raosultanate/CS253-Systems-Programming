#include "substitute.h"
#include <stdio.h>
#include <string.h>

int doSubstitute(char *pattern, char *string)
{
    char buff[1024]; //buff size
    int buffLength;
    int stringLength;
    int patternLength;
    char *patternPointer;

    while (fgets(buff, 1024, stdin) != NULL) //contains each sentense at a time, runs until it reaches the end of the file.

    {
        buffLength = strlen(buff);       //contains the length of the sentence
        stringLength = strlen(string);   //contains the length of the user passed string
        patternLength = strlen(pattern); //contains the length of the user passed pattern

        if (buffLength == 1024)
        {
            return -1;
            //line too long, exceeds 1024 characters.
        }

        //the patternPointer is inside the loop because if there are multiple occurence of the pattern inside the sentence.
        if (patternLength == 0)
        {
            return -1;
        }

        else
        {
            for (int i = 0; i < 1024; i++)
            {
                patternPointer = strstr(buff, pattern); //contains the pointer to the pattern identified inside of the string.
                if (patternPointer != NULL)
                {
                    strncpy(patternPointer, string, stringLength);
                }
            }

            fputs(buff, stdout);
        }
    }
    return 0;
}
