//
// Created by User on 12/05/2019.
//

#include "header.h"

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
    //args[0] = upperCase(args[0]);
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
            //upperCase(equals);

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

        /*
        if (check == 5)
        {
            strcat(systemArgs[check].value, "> ");
        }
        */
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
        //upperCase(equals);

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