//
// Created by User on 25/03/2019.
//

#include "header.h"

void directoryChanger(char **args)
{
    //if nothing is passed to the argument
    if (args[1] == NULL)
    {
        printf("No directory location was passed\n");
    }
    //if ".." are passed to the argument
    else
    {
        //backup of current location
        char *backup = malloc(sizeof(systemArgs[2].value));
        strcpy(backup, systemArgs[2].value);

        int k = 1;
        int n = 0;
        //need to go through the whole part and see if different folders where written in the same argument
        while (args[k][n] != '\0') {
            //if 2 dots are placed after each other
            if ((args[k][n] == '.' && args[k][n + 1] == '.' && args[k][n + 2] == '/') || (args[k][n] == '.' && args[k][n + 1] == '.' && args[k][n + 2] == '\0')) {
                //method to go to the parent folder
                int l = 0;
                for (int m = 0; m < strlen(systemArgs[2].value); m++) {
                    if (systemArgs[2].value[m] == '/') {
                        l = m;
                    }
                }
                //storing the old location
                strcpy(systemArgs[7].value, systemArgs[2].value);
                //cropping the location to the new location in mind
                systemArgs[2].value[l] = '\0';

                //changing the location
                if (chdir(systemArgs[2].value) != 0)
                {
                    printf("Location change error\n");
                    strcpy(systemArgs[8].value, "1");
                }

                //to go over the first dot
                n++;
                //to go over the second dot
                n++;
            }
                //for if the user enters current location as "./"
            else if (args[k][n] == '.' && args[k][n + 1] == '/') {
                //there is no reallocation if you are requesting the same folder
                n++;
            } else {
                char *location = malloc(256);
                //setting up the new location
                strcpy(location, systemArgs[2].value);
                strcat(location, "/");
                //and looping to add the characters 1 by 1
                do {
                    //concatenating the character to the string
                    size_t length = strlen(location);
                    location[length] = args[k][n];
                    location[length + 1] = '\0';
                    //strcat(location, args[k][n]);

                    n++;
                    if (args[k][n] == '\\') {
                        strcat(location, " ");
                        k++;
                        //resetting the n pointer since a new token is being used
                        n = 0;
                    }
                } while (args[k][n] != '/' && args[k][n] != '\0');

                if (chdir(location) != 0) {
                    printf("Location %s does not exist\n", location);
                    strcpy(systemArgs[2].value, backup);
                    chdir(backup);
                    strcpy(systemArgs[8].value, "1");
                    break;
                } else {
                    strcpy(systemArgs[2].value, location);
                    strcpy(systemArgs[7].value, backup);
                    strcpy(systemArgs[8].value, "0");
                }
                free(location);
            }
            //to go over the "/" and not over "\0"
            if (args[k][n] != '\0') {
                n++;
            }

            free(backup);
        }
    }
}

bool Commands (char **args, int *systemVariables, char **envp)
{
    bool exit = false;

    //if no arguments are passed then do nothing
    if (args[0] == 0)
    {
        return exit;
    }

    size_t fileOpened;
    fileOpened = Redirection(args);

    //check again to see that the file input has worked
    if (args[0] == 0)
    {
        return false;
    }
    if (strchr(args[0], '='))
    {
        setVariable(args, systemVariables);
    }
    //if the argument exit is passed as the first argument then exit the program
    else if (strcmp(args[0], "exit") == 0)
    {
        printf("BYE!\n");
        return true;
    }
    else if(strcmp(args[0], "print")==0)
    {
        printing(args, systemVariables[0]);
    }
    else if(strcmp(args[0], "all")==0)
    {
        printSystemVariables(systemVariables[0]);
    }
    else if(strcmp(args[0], "chdir")==0)
    {
        directoryChanger(args);
    }
    else if(strcmp(args[0], "source")==0)
    {
        fileOpened = sourceExecution(args);
        exit = prompting(systemVariables, envp);
    }
    else
    {
        externalFunctions(systemVariables, args, envp);
    }

    //to remove the file descriptor
    if (fileOpened != 0 && fileOpened != -1)
    {
        close(fileOpened);
    }

    return exit;
}

int setSystemVariables()
{
    strcpy(systemArgs[0].key,"HOME");
    strcpy(systemArgs[0].value,getenv("HOME"));

    strcpy(systemArgs[1].key,"PATH");
    strcpy(systemArgs[1].value,getenv("PATH"));

    strcpy(systemArgs[2].key,"PWD");
    strcpy(systemArgs[2].value,getenv("PWD"));

    strcpy(systemArgs[3].key,"USER");
    strcpy(systemArgs[3].value,getenv("USER"));

    //getting the file location of the shell
    pid_t ID = getpid();
    char process[MAX_ARGS];
    char location[MAX_ARGS];
    //strcpy(process, "/proc/");
    //strcat(process, &ID);
    //strcat(process, "/exe");
    sprintf(process, "/proc/%d/exe", ID);

    strcpy(systemArgs[4].key,"SHELL");
    if (readlink(process, location, MAX_ARGS) == -1) {
        perror("readlink");
        strcpy(systemArgs[4].value, "error");
    }
    else {
        strcpy(systemArgs[4].value,location);
    }

    strcpy(systemArgs[5].key,"PROMPT");
    strcpy(systemArgs[5].value,"eggshell-1.0");

    strcpy(systemArgs[6].key, "TERMINAL");
    strcpy(systemArgs[6].value, ttyname(STDIN_FILENO));

    strcpy(systemArgs[7].key, "OLDPWD");
    strcpy(systemArgs[7]. value, getenv("OLDPWD"));

    strcpy(systemArgs[8].key, "EXITCODE");
    strcpy(systemArgs[8].value, "0");

    fileLines = 0;

    return 9;
}