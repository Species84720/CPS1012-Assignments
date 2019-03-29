//
// Created by User on 25/03/2019.
//

#ifndef ASSIGNMENT_HEADER_H
#define ASSIGNMENT_HEADER_H

#include <stdio.h>
#include "linenoise-master/linenoise.h"
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/fcntl.h>

#define MAX_ARGS 255

typedef struct linked_list
{
    //to store the key name of a value
    char key[256];
    //to store the value itself
    char value[256];
}store;

store systemArgs[500];

int checkVariable(char args[], int systemVariables);
void setVariable(char **args, int *systemVariables);
char *upperCase(char *args);
void prompting(int *systemVariables);
void tiny_shell();

bool Commands (char **args, int *systemVariables);
int setSystemVariables();

char *substr(char *string, int left, int right);
void printing(char **args, int systemVariables);
void printSystemVariables(int SystemVariables);

#endif //ASSIGNMENT_HEADER_H
