//
// Created by User on 25/03/2019.
//

#include "header.h"

bool pipeHandling(char *line, int *systemVariables, char **envp)
{
    //backup of in and out
    int backupin = dup(fileno(stdin));
    int backupout = dup(fileno(stdout));

    int pipeCount = 0;

    //tokening by pipes
    char *pipeArgs[MAX_ARGS];
    pipeCount = tokening(line, pipeArgs, '|');

    //should accept 0 for when there are no pipes
    int i = 0;
    while (pipeArgs[i] != NULL)
    {
        //create pipes
        int pipeConnect[2];
        int pipeVariables[2];
        if ( pipe(pipeConnect) == -1 )
        {
            printf("Pipe for information was not created\n");
            _exit(0);
        }
        if ( pipe(pipeVariables) == -1 )
        {
            printf("Pipe for variables was not created\n");
            _exit(0);
        }

        //passing only the needed data before each pipe
        char *args[MAX_ARGS];
        tokening(pipeArgs[i], args, ' ');

        //creating the shared memory
        store *sharedMemory = mmap(NULL, 500*sizeof(store), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

        //carrying out the fork
        pid_t ID;
        ID = fork();
        killPID = ID;

        //child process
        if (ID == 0)
        {
            bool exit;

            if (i != pipeCount)
            {
                //set the pipe to take the stdout
                close(pipeConnect[PIPE_READ]);
                dup2(pipeConnect[PIPE_WRITE], fileno(stdout));
            }

            exit = Commands(args, systemVariables, envp);
            //and set stdout back to normal since it already sent the data required
            dup2(backupout, fileno(stdout));

            close(pipeVariables[PIPE_READ]);
            write(pipeVariables[PIPE_WRITE], systemVariables, sizeof(int*));
            close(pipeVariables[PIPE_WRITE]);

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

            //setting up the terminate signal
            killPID = 0;

            if (WIFEXITED(status))
            {
                status = WEXITSTATUS(status);

                close(pipeConnect[PIPE_WRITE]);
                if (i + 1 > pipeCount)
                {
                    if (fileEditing)
                    {
                        fileEditing = false;
                    }
                    else
                    {
                        /*
                        char buffer[1];
                        while (read(pipeConnect[0], buffer, 1) > 0)
                        {
                            write(fileno(stdout), buffer, fileno(stdout));
                        }
                         */
                        //and set stdin to normal as it is now already filled
                        dup2(backupin, fileno(stdin));
                    }
                }
                else
                {
                    dup2(pipeConnect[PIPE_READ], fileno(stdin));
                }
                close(pipeConnect[PIPE_READ]);

                close(pipeVariables[PIPE_WRITE]);
                read(pipeVariables[PIPE_READ], systemVariables, sizeof(int*));
                close(pipeVariables[PIPE_READ]);
                for (int l = 0; l < systemVariables[0]; l++)
                {
                    systemArgs[l] = sharedMemory[l];
                }

                //changing the parents chdir
                if (chdir(systemArgs[2].value) != 0)
                {
                    printf("Location change error\n");
                    //taking back the previous location
                    strcpy(systemArgs[2].value, systemArgs[7].value);
                }

                if (status == 1)
                {
                    return true;
                }
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

bool prompting(int *systemVariables, char **envp)
{
    //setting up the terminate signal
    killPID = 0;
    signal(SIGINT, signalHandler);

    //backup of stdin
    int backupin = dup(fileno(stdin));
    int backupout = dup(fileno(stdout));
    fileEditing = false;

    //to see if exit was passed to the shell
    bool exit = false;

    char prompt[MAX_ARGS];
    strcpy(prompt, systemArgs[5].value);
    strcat(prompt, ":");
    strcat(prompt, systemArgs[2].value);
    strcat(prompt, "# ");

    char *line = NULL;//, *args[MAX_ARGS];
    while (exit == false)
    {
        while (exit == false && (line = linenoise(prompt)) != NULL)
        {
            //to add history to the shell
            linenoiseHistoryAdd(line);

            //used before the forking of the command handler
            //tokening(line, args, ' ');

            exit = pipeHandling(line, systemVariables, envp);

            //checking if a file is currently being updated
            int check = fileHandling(backupin, backupout);
            if (check == 0)
            {
                return exit;
            }

            // Free allocated memory
            linenoiseFree(line);

            //to make sure the directory is still the same
            strcpy(prompt, systemArgs[5].value);
            strcat(prompt, ":");
            strcat(prompt, systemArgs[2].value);
            strcat(prompt, "# ");
        }
        //printing if ctrl-c was clicked
        /*
        if (exit == false)
        {
            printf("\033[A\033[K");
            printf("%s^C\n", prompt);
        }
        */
    }
    return exit;
}

void tiny_shell(char **envp)
{
    //setting the system variables and the amount of variables
    int *systemVariables = malloc(sizeof(int));
    systemVariables[0] = setSystemVariables();

    prompting(systemVariables, envp);
}