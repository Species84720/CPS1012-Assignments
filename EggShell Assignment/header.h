//
// Created by User on 25/03/2019.
//

#ifndef ASSIGNMENT_HEADER_H
#define ASSIGNMENT_HEADER_H

#define _GNU_SOURCE
#include <stdio.h>
#include "linenoise-master/linenoise.h"
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define MAX_ARGS 255
#define PIPE_READ 0
#define PIPE_WRITE 1

typedef struct linked_list
{
    //to store the key name of a value
    char key[256];
    //to store the value itself
    char value[256];
}store;

store systemArgs[500];
int fileLines;
//bool fileEditing;
pid_t killPID;

//main.c
void signalHandler(int signal);

//VariableHandler.c
int checkVariable(char args[], int systemVariables);
void setVariable(char **args, int *systemVariables);

//tinyShell.c
bool prompting(int *systemVariables, char **envp);
void tiny_shell(char **envp);

//TextHandlers.c
int tokening(char *line, char *args[MAX_ARGS], char *With);
char *substr(char *string, int left, int right);
char *processSlash(char **args, char *location, int start);
void removeChar(FILE *file, char character, char *location);
//char *upperCase(char *args);

//FileHandler.c
int fileHandling(int backupin, int backupout);
void ChangeArgs(char **args, int k);
size_t Redirection(char **args);
bool stringCheck(char *string, bool print);

//Controllers.c
size_t sourceExecution(char **args);
bool Commands (char **args, int *systemVariables, char **envp);
int setSystemVariables();

//Printing.c
void printing(char **args, int systemVariables);
void printSystemVariables(int SystemVariables);

//external.c
void externalFunctions(int *systemVariables, char **args, char **envp);

#endif //ASSIGNMENT_HEADER_H
