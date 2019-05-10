//
// Created by User on 31/03/2019.
//

#include "header.h"

void externalFunctions(char **args, char **envp)
{
    pid_t ID;
    ID = fork();

    //child process
    if (ID == 0)
    {
        int error = -1;
        bool exit = false;
        char *path = malloc(sizeof(char *) * 256);
        //copy the whole string
        strcpy(path, systemArgs[1].value);
        //tokenize the string
        strtok(path, ":");
        while (exit == false && path != NULL)
        {
            char *pathChange = malloc(sizeof(char *) * 256);
            strcpy(pathChange, path);
            strcat(pathChange, "/");
            strcat(pathChange, args[0]);
            //execution
            error = execvpe(pathChange, args, envp);
            //execution is successful
            if (error == 0)
            {
                printf("success\n");
                exit = true;
            }
            path = strtok(NULL, ":");
        }
        //execution has failed
        if (error == -1)
            printf("Function was not executed correctly\n");
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