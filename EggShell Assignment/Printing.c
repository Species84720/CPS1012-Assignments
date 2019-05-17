//
// Created by User on 25/03/2019.
//

#include "header.h"

void printing(char **args, int systemVariables)
{
    char toprint[MAX_ARGS] = "";

    //skipping the print command
    int k = 1;

    //to loop through all the parameters sent to the printer
    while (args[k] != NULL) {
        if (args[k][0] == '\\')
        {
            char *string = substr(args[k], 1, 0);
            strcat(toprint, string);
            strcat(toprint, " ");
            //printf("%s ", string);
            free(string);
        }
        else if(args[k][0] == '>' || args[k][0] == '<')
        {
            //to stop when a '>' is found
            break;
        }
        else if(args[k][0] == '$')
        {
            int check;
            char c[MAX_ARGS];
            c[0] = '#';
            char *string = substr(args[k], 1, 0);

            //args[k] = upperCase(args[k]);
            if (!stringCheck(string, false))
            {
                strcpy(c, &string[strlen(string) - 1]);
                string = substr(string, 0, 1);
                if (!stringCheck(string, true))
                {
                    return;
                }
            }

            check = checkVariable(string, systemVariables);
            if (check != -1)
            {
                strcat(toprint, systemArgs[check].value);
                //printf("%s", systemArgs[check].value);
                if (!strchr(c, '#'))
                {
                    strcat(toprint, c);
                    //printf("%c", c);
                }
                strcat(toprint, " ");
                //printf(" ");
            }
            else
            {
                printf("Variable %s was not found as a system variable!\n", string);
                free(string);
                return;
            }
            free(string);
        }
        else
        {
            strcat(toprint, args[k]);
            strcat(toprint, " ");
            //printf("%s ", args[k]);
        }
        k++;
    }
    printf("%s", toprint);
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