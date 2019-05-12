//
// Created by User on 12/05/2019.
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
    return tokenIndex - 1;
}

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
void removeChar(FILE *file, char character, char *location)
{
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

//only needed if all variables are wished to be upper case
/*
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
 */