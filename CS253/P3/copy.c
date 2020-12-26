#include "copy.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doCopy(void)
{

    char buff[1024];

    while (fgets(buff, 1024, stdin) != NULL) //contains each sentense at a time, runs until it reaches the end of the file.
    {
        int buffLength = strlen(buff);
        if (buffLength == 1024)
        {
            return -1;
            //line too long, exceeds 1024 characters.
        }

        printf("%s", buff);
    }
    return 0;
}
