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
            if (args[k][n] == '.' && args[k][n + 1] == '.') {
                //method to go to the parent folder
                int l = 0;
                for (int m = 0; m < strlen(systemArgs[2].value); m++) {
                    if (systemArgs[2].value[m] == '/') {
                        l = m;
                    }
                }
                //cropping the location to the new location in mind
                systemArgs[2].value[l] = '\0';

                //changing the location
                chdir(systemArgs[2].value);

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
                } else {
                    strcpy(systemArgs[2].value, location);
                }
                free(location);
            }
            //to go over the "/" and not over "\0"
            if (args[k][n] != '\0') {
                n++;
            }
        }
    }
}

char *processSlash(char **args, char *location, int start)
{
    //looping through the arguments to make sure there is no '\' to show a file with a space
    strcpy(location, args[start]);
    if (strchr(args[start], '\\') != NULL) {
        //remove the '\'
        location = substr(location, 0, 1);
        size_t length = strlen(location);
        location[length] = ' ';
        location[length + 1] = '\0';
        int k = start + 1;
        int n = 0;
        while (args[k][n] != '\0') {
            //concatenating the character to the string
            length = strlen(location);
            location[length] = args[k][n];
            location[length + 1] = '\0';
            n++;

            if (args[k][n] == '\\') {
                strcat(location, " ");
                k++;
                //resetting the n pointer since a new token is being used
                n = 0;
            }
        }
    }

    return location;
}

//to remove a certain character from a string - to convert windows file to ubuntu really
//and to add an enter at the end of file if needed
void removeChar(FILE *file, char character, char *location){
    int c = 0;
    int n = 0;

    //go to the end of file
    fseek(file, 0, SEEK_END);
    //take the size of file
    long f_size = ftell(file);
    //back to the start
    fseek(file, 0, SEEK_SET);
    char *code = malloc(f_size);

    while ((c = fgetc(file)) != EOF)
    {
        if ((char)c != character)
        {
            code[n++] = (char) c;
        }
        if ((char)c == '\n')
        {
            fileLines++;
        }
    }
    if (code[n - 1] != '\n')
    {
        code[n++] = '\n';
        fileLines++;
    }
    code[n] = '\0';

    //close the read file
    fclose(file);
    //open the write file
    file = fopen(location, "w");
    fprintf(file, "%s", code);
    fclose(file);
}

void sourceExecution(char **args)
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
        dup2(open(location, O_RDONLY), fileno(stdin));

        fclose(openfd);
    }
    else
    {
        printf("The file %s does not exit!\n", location);
    }
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

        //tokenize the new string to take place of the old arguments
        tokening(code, args);
    }
    else
    {
        printf("The file %s does not exit!\n", location);
        args[0] = 0;
    }
}

bool Commands (char **args, int *systemVariables, char **envp)
{
    //if no arguments are passed then do nothing
    if (args[0] == 0)
    {
        return false;
    }

    //loop to find any ">" or ">>" or "<"
    int k = 0;
    do
    {
        if (strcmp(args[k], ">") == 0)
        {
            dup2(open(args[k + 1], O_RDWR | O_CREAT), fileno(stdout));
            break;
        }
        else if (strcmp(args[k], ">>") == 0)
        {
            dup2(open(args[k + 1], O_RDWR | O_CREAT | O_APPEND), fileno(stdout));
            break;
        }
        else if (strcmp(args[k], "<") == 0)
        {
            //changing the arguments to the new one's with the file commands included
            ChangeArgs(args, k);
            break;
        }
        k++;
    } while (args[k] != NULL);

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
        sourceExecution(args);
    }
    else
    {
        externalFunctions(args, envp);
    }

    return false;
}

int setSystemVariables()
{
    strcpy(systemArgs[0].key,"HOME");
    strcpy(systemArgs[0].value,getenv("HOME"));

    strcpy(systemArgs[1].key,"PATH");
    strcpy(systemArgs[1].value,getenv("PATH"));

    strcpy(systemArgs[2].key,"CWD");
    strcpy(systemArgs[2].value,getenv("PWD"));

    strcpy(systemArgs[3].key,"USER");
    strcpy(systemArgs[3].value,getenv("USER"));

    strcpy(systemArgs[4].key,"SHELL");
    strcpy(systemArgs[4].value,getenv("SHELL"));

    strcpy(systemArgs[5].key,"PROMPT");
    strcpy(systemArgs[5].value,"eggshell-1.0> ");

    strcpy(systemArgs[6].key, "TERMINAL");
    strcpy(systemArgs[6].value, ttyname(STDIN_FILENO));

    fileLines = 0;

    return 7;
}