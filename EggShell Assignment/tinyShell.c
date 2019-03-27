//
// Created by User on 25/03/2019.
//

#include "header.h"

void tokening(char *token, char *line, char *args[MAX_ARGS])
{
    int tokenIndex;
    token = strtok(line, " ");

    for (tokenIndex = 0; token != NULL && tokenIndex < MAX_ARGS - 1; tokenIndex++) {
        args[tokenIndex] = token;
        token = strtok(NULL, " ");
    }

    // set last token to NULL
    args[tokenIndex] = NULL;
}

int checkVariable(char args[], int systemVariables)
{
    int l = 0;
    for (l = 0; l < systemVariables; l++)
    {
        if (strcmp(substr(args, 1, 0), systemArgs[l].key) == 0)
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
    int k = 1;
    while (args[k] != '\0')
    {
        printf("%c %d\n", args[k], k);
        args[k] = toupper(args[k]);
        k++;
    }
    printf("hello\n");
}

void setVariable(char **args, int *systemVariables)
{
    int check;

    //finding the "=" in your string
    char *equals;
    //skipping the '$' and the first letter of the variable
    // - if the equal is within these 2 then the variable is nothing and that cannot happen
    equals = strstr(args[0], "=");
    //if no equals is found then an error is given
    if (equals == NULL)
    {
        printf("No \"=\" condition was found in the condition\n");
        return;
    }
    else if (args[0][1] == '=')
    {
        printf("No variable name was given to value %s\n", substr(equals, 1, 0));
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
        strcpy(systemArgs[check].value, equals);
        return;
    }

    //if not found create a new variable
    systemVariables[0] = systemVariables[0] + 1;

}

void tiny_shell()
{
    //to see if exit was passed to the shell
    bool exit = false;

    //setting the system variables and the amount of variables
    int *systemVariables = malloc(sizeof(int));
    systemVariables[0] = setSystemVariables();

    char *line, *token = NULL, *args[MAX_ARGS];

    while (exit == false && (line = linenoise("prompt> ")) != NULL) {
        tokening(token, line, args);
        exit = Commands(args, systemVariables);

        // Free allocated memory
        linenoiseFree(line);
    }
}