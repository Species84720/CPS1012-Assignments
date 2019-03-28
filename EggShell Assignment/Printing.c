//
// Created by User on 25/03/2019.
//

#include "header.h"

char *substr(char *string, int left, int right) {
    //setting the new string to take a part of the old string
    char *newString = malloc(sizeof(string));

    //setting the start of the new string
    strcpy(newString, "");

    //checking the length of string
    int length = 0;
    int n = 0;
    while (string[n] != '\0')
    {
        length++;
        n++;
    }
    //immediately removing the '$'
    length = length - left;

    //looping to fill the new string
    int m=0;
    n=0;
    while(string[n]!='\0')
    {
        if ( n >= left && m < (length - right) ){
            newString[m] = string[n];
            m++;
        }
        n++;
    }

    //setting the final
    newString[m]='\0';
    return newString;
}

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
        else if(args[k][0] == '$')
        {
            int check;
            args[k] = upperCase(args[k]);
            check = checkVariable(args[k], systemVariables);
            if (check != -1)
            {
                printf("%s", systemArgs[check].value);
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