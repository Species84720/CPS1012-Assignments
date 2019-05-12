//
// Created by User on 31/03/2019.
//

#include "header.h"

size_t sourceExecution(char **args)
{
    //int fd = dup(fileno(stdin));
    FILE *openfd;

    //looping through the arguments to make sure there is no '\' to show a file with a space
    char *location = malloc(256);
    location = processSlash(args, location, 1);

    //open file
    if ((openfd = fopen(location, "r")) != NULL)
    {
        //cleaning the files from any possible '\r'
        removeChar(openfd, '\r', location);

        //now reading and using the data - changing the stdin as the file instead of the terminal
        size_t openedFile = open(location, O_RDONLY);
        dup2(openedFile, fileno(stdin));

        fclose(openfd);

        return openedFile;
    }
    else
    {
        printf("The file %s does not exit!\n", location);
        return 0;
    }
}

void setEnvParameters(char **envp, int systemVariables)
{
    int k = 0;
    //going through all the envp values
    while(envp[k] != NULL)
    {
        //setting variables to copy the envp so as to work on it
        char stringGet[strlen(envp[k])];
        char *stringSplit[MAX_ARGS];
        strcpy(stringGet, envp[k]);
        tokening(stringGet, stringSplit, '=');

        for (int i = 0; i < systemVariables; i++)
        {
            //if the variable needed is found
            if (strcmp(stringSplit[0], systemArgs[i].key) == 0)
            {
                strcpy(envp[k], stringSplit[0]);
                strcat(envp[k], "=");
                strcat(envp[k], systemArgs[i].value);
                break;
            }
        }
        k++;
    }
}

void externalFunctions(int *systemVariables, char **args, char **envp)
{
    //update environmental parameters to the one's we have
    setEnvParameters(envp, systemVariables[0]);

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
            //execution is successful - never executes
            if (error == 0)
            {
                printf("success\n");
                exit = true;
            }
            path = strtok(NULL, ":");
        }
        //execution has failed
        if (error == -1)
        {
            printf("Function does not exist\n");
            _exit(0);
        }
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