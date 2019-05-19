//
// Created by User on 12/05/2019.
//

#include "header.h"

int fileHandling(int backupin, int backupout)
{
    /*
    if (fileEditing)
    {
        dup2(backupout, fileno(stdout));
    }
    */

    //checking if we are currently getting data from a file for when source occurs
    if (fileLines != 0)
    {
        fileLines--;
        if (fileLines == 0)
        {
            //closing the file and giving back control to the terminal and go back
            fflush(stdin);
            dup2(backupin, fileno(stdin));
            return 0;
        }
    }
    return 1;

    //was used before the forking to see if source was reading from a file
    /*
    if (backupin != fileno(stdin))
    {
        //checking if we are currently getting data from a file
        if (fileLines != 0)
        {
            fileLines--;
            if (fileLines == 0)
            {
                //closing the file and giving back control to the terminal
                fflush(stdin);
                dup2(backupin, fileno(stdin));
            }
        }
    }
    */
}

void ChangeArgs(char **args, int k)
{
    //checking if file exists
    FILE *file;
    char *location = malloc(256);
    location = processSlash(args, location, k + 1);
    if ((file = fopen(location, "r")) != NULL)
    {
        //considering that longest command will be less than 255 characters
        char *code = malloc(MAX_ARGS);
        //placing the current arguments to the new string
        for (int i = 0; i < k; i++)
        {
            strcat(code, args[i]);
            strcat(code, " ");
        }
        //placing the file onto the string
        char *temp = malloc(MAX_ARGS);
        //stopping at the sign of a new line or EOF
        fgets(temp, MAX_ARGS, file);
        strcat(code, temp);
        free(temp);

        int temporal = 0;
        for (int i = 0; i < strlen(location); i++)
        {
            if(location[i] == ' ')
            {
                temporal ++;
            }
        }
        //1 to skip the "<", 1 to skip the first part of the file and temporal to skip the rest of the file name
        k = k + 2 + temporal;
        while (args[k] != NULL)
        {
            strcat(code, " ");
            strcat(code, args[k]);
            k++;
        }

        //tokenize the new string to take place of the old arguments
        tokening(code, args, " ");
    }
    else
    {
        printf("The file %s does not exit!\n", location);
        strcpy(systemArgs[8].value, "1");
        args[0] = 0;
    }
}

size_t Redirection(char **args)
{
    int k = 0;
    //find any possible "<"
    do
    {
        if (strcmp(args[k], "<") == 0)
        {
            //changing the arguments to the new one's with the file commands included
            ChangeArgs(args, k);
        }
        k++;
    } while (args[k] != NULL);

    k = 0;
    //find any possible "<<<"
    do
    {
        if (strcmp(args[k], "<<<") == 0)
        {
            args[k] = NULL;
            //size_t openedFile = open(args[k + 1], O_RDONLY);
            //dup2(openedFile, fileno(stdin));
            //return openedFile;

            //creating a pipe to transform the string into a file
            int pipes[2];
            if (pipe(pipes) == -1)
            {
                printf("Pipe was unsuccessful\n");
                strcpy(systemArgs[8].value, "1");
                return 0;
            }
            else
            {
                write(pipes[PIPE_WRITE], args[k + 1], sizeof(char*));
                close(pipes[PIPE_WRITE]);
                dup2(pipes[PIPE_READ], fileno(stdin));
            }
            break;
        }
        k++;
    } while (args[k] != NULL);

    k = 0;
    //now for output handling - if to file or not
    do
    {
        if (strcmp(args[k], ">") == 0)
        {
            size_t openedFile = open(args[k + 1], O_RDWR | O_CREAT | O_TRUNC);
            dup2(openedFile, fileno(stdout));
            //fileEditing = true;
            args[k] = NULL;
            return openedFile;
        }
        else if (strcmp(args[k], ">>") == 0)
        {
            size_t openedFile = open(args[k + 1], O_RDWR | O_CREAT | O_APPEND);
            dup2(openedFile, fileno(stdout));
            //fileEditing = true;
            args[k] = NULL;
            return openedFile;
        }
        k++;
    } while (args[k] != NULL);

    return 0;
}