//
// Created by User on 31/03/2019.
//

#include "header.h"

void externalFunctions(char **args)
{
    pid_t ID;
    ID = fork();
    int *status = 0;

    //child process
    if (ID == 0)
    {
        int error = 0;
        error = execvp(args[0], args);
        if (error == -1)
            printf("Function was not executed correctly\n");
        exit(0);
    }
    //parent process
    else if (ID > 0)
    {
        //waiting for the child
        wait(NULL);
    }
    else
        printf("Error forking was not executed!!!\n");
}