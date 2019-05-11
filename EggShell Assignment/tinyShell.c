//
// Created by User on 25/03/2019.
//

#include "header.h"

int tokening(char *line, char *args[MAX_ARGS], char With)
{
    char *token = NULL;
    int tokenIndex;
    token = strtok(line, &With);

    for (tokenIndex = 0; token != NULL && tokenIndex < MAX_ARGS - 1; tokenIndex++) {
        args[tokenIndex] = token;
        token = strtok(NULL, &With);
    }

    // set last token to NULL
    args[tokenIndex] = NULL;

    //-1 since there is one less pipe then tokens
    // and another -1 because the for loop above adds an extra +1 in the end
    return tokenIndex - 2;
}

int checkVariable(char args[], int systemVariables)
{
    int l = 0;
    for (l = 0; l < systemVariables; l++)
    {
        if (strcmp(args, systemArgs[l].key) == 0)
        {
            return l;
        }
    }

    //seeing if the variable was found and if not return the error
    if (l == systemVariables)
    {
        return -1;
    }
}

char *upperCase(char *args)
{
    int k = 0;
    if (args[k] == '$')
    {
        k++;
    }
    while (args[k] != '\0')
    {
        args[k] = toupper(args[k]);
        k++;
    }
    return args;
}

void setVariable(char **args, int *systemVariables)
{
    int check;

    //finding the "=" in your string
    char *equals;
    //if the equal is within these 2 then the variable is nothing and that cannot happen
    equals = strstr(args[0], "=");
    //if no equals is found then an error is given
    if (equals == NULL)
    {
        printf("No \"=\" condition was found in the condition\n");
        return;
    }
    else if (args[0][0] == '=')
    {
        printf("No variable name was given to value %s\n", equals);
        return;
    }

    //setting the "=" position to null
    equals[0] = '\0';
    //upper case the variables
    args[0] = upperCase(args[0]);
    check = checkVariable(args[0], systemVariables[0]);
    //setting the pointer to after the "="
    equals = &equals[1];
    //if found change existent variable
    if (check != -1)
    {
        //allocating the split value to the current variable
        if(equals[0] != '$')
        {
            strcpy(systemArgs[check].value, equals);
        }
        else
        {
            //since it is a variable
            upperCase(equals);

            int checkVar;
            checkVar = checkVariable(substr(equals, 1, 0), systemVariables[0]);
            if (checkVar != -1)
            {
                strcpy(systemArgs[check].value, systemArgs[checkVar].value);
            }
            else
            {
                printf("\nVariable %s was not found as a system variable!\n", substr(args[0], 1, 0));
            }
        }

        if (check == 5)
        {
            strcat(systemArgs[check].value, "> ");
        }
        return;
    }

    //if not found create a new variable
    if(equals[0] != '$')
    {
        strcpy(systemArgs[systemVariables[0]].key, args[0]);
        strcpy(systemArgs[systemVariables[0]].value, equals);
    }
    else
    {
        //since it is a variable
        upperCase(equals);

        int checkVar;
        checkVar = checkVariable(substr(equals, 1, 0), systemVariables[0]);
        if (checkVar != -1)
        {
            strcpy(systemArgs[systemVariables[0]].key, args[0]);
            strcpy(systemArgs[systemVariables[0]].value, systemArgs[checkVar].value);
        }
        else
        {
            printf("\nVariable %s was not found as a system variable!\n", substr(equals, 1, 0));
        }
    }

    //since the values are back by a value of 1 then the addition can be done after the copying
    systemVariables[0] = systemVariables[0] + 1;
}

void signalHandler(int signal)
{
    //getting the pid of the current process
    //pid_t process = currentPID;
    //int success = kill(process, SIGINT);
}

void fileHandling(int backupin)
{
    if (backupin != fileno(stdin)) {
        //checking if we are currently getting data from a file
        if (fileLines != 0) {
            fileLines--;
            if (fileLines == 0) {
                //closing the file and giving back control to the terminal
                fflush(stdin);
                dup2(backupin, fileno(stdin));
            }
        }
    }
}

bool pipeHandling(char *line, int *systemVariables, char **envp)
{
    int k = 0;
    int pipeCount = 0;
    int pipePosition = 0;

    //tokening by pipes
    char *pipeArgs[MAX_ARGS];
    pipeCount = tokening(line, pipeArgs, '|');

    //should accept 0 for when there are no pipes
    int i = 0;
    while (pipeArgs[i] != NULL)
    {
        //create pipe
        int pipeConnect[2];
        if ( pipe(pipeConnect) == -1 )
        {
            printf("Pipe was not created\n");
            _exit(0);
        }

        //passing only the needed data before each pipe
        char *args[MAX_ARGS];
        tokening(pipeArgs[i], args, ' ');

        //creating the shared memory
        int protection = PROT_READ | PROT_WRITE;
        int visibility = MAP_ANONYMOUS | MAP_SHARED;
        store *sharedMemory = mmap(NULL, 500*sizeof(store), protection, visibility, -1, 0);

        //carrying out the fork
        pid_t ID;
        ID = fork();

        //child process
        if (ID == 0)
        {
            bool exit;
            exit = Commands(args, systemVariables, envp);

            close(pipeConnect[0]);
            write(pipeConnect[1], systemVariables, sizeof(int*));
            close(pipeConnect[1]);

            //filling the shared memory
            memcpy(sharedMemory, systemArgs, 500*sizeof(store));

            if (exit == false)
            {
                _exit(0);
            }
            else
            {
                _exit(1);
            }
        }
        //parent process
        else if (ID > 0)
        {
            int status = 0;
            //waiting for the child
            waitpid(ID, &status, 0);
            //wait(NULL);

            if (WIFEXITED(status))
            {
                status = WEXITSTATUS(status);

                if (status == 1)
                {
                    return true;
                }
            }

            close(pipeConnect[1]);
            read(pipeConnect[0], systemVariables, sizeof(int*));
            close(pipeConnect[0]);
            for (int l = 0; l < systemVariables[0]; l++) {
                systemArgs[l] = sharedMemory[l];
            }
        }
        else
            printf("Error forking was not executed!!!\n");

        munmap(sharedMemory, 500* sizeof(store));

        //next pipe set
        i++;
    }

    return false;
}

void prompting(int *systemVariables, char **envp)
{
    //backup of stdin
    int backupin = dup(fileno(stdin));
    int backupout = dup(fileno(stdout));

    //to see if exit was passed to the shell
    bool exit = false;

    char *line = NULL;//, *args[MAX_ARGS];
    while (exit == false && (line = linenoise(systemArgs[5].value)) != NULL) {
        //setting up the terminate signal
        //signal(SIGINT, signalHandler);

        fileHandling(backupin);

        //tokening(line, args, ' ');
        exit = pipeHandling(line, systemVariables, envp);
        //exit = Commands(args, systemVariables, envp);

        //checking if '>' was introduced into the command
        if (backupout != fileno(stdout)) {
            dup2(backupout, fileno(stdout));
        }

        // Free allocated memory
        linenoiseFree(line);
    }
}

void tiny_shell(char **envp)
{
    //setting the system variables and the amount of variables
    int *systemVariables = malloc(sizeof(int));
    systemVariables[0] = setSystemVariables();

    prompting(systemVariables, envp);
}