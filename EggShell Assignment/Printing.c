//
// Created by User on 25/03/2019.
//

#include "header.h"

void printing(char **args, int systemVariables)
{
    //skipping the print command
    int k = 1;

    //to loop through all the parameters sent to the printer
    while (args[k] != NULL) {
        if (args[k][0] == '\\')
        {
            printf("%s ", substr(args[k], 1, 0));
        }
        else if(args[k][0] == '>' || args[k][0] == '<')
        {
            //to stop when a '>' is found
            break;
        }
        else if(args[k][0] == '$')
        {
            int check;
            //args[k] = upperCase(args[k]);
            check = checkVariable(substr(args[k], 1, 0), systemVariables);
            if (check != -1)
            {
                printf("%s ", systemArgs[check].value);
            }
            else
            {
                printf("Variable %s was not found as a system variable!", substr(args[k], 1, 0));
            }
        }
        else
        {
            printf("%s ", args[k]);
        }
        k++;
    }
    printf("\n");
}

void printSystemVariables(int SystemVariables)
{
    printf("\n");
    for (int k = 0; k < SystemVariables; k++)
    {
        printf("%s = \"%s\"\n",systemArgs[k].key, systemArgs[k].value);
    }
    printf("\n");
}