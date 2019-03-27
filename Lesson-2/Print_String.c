//
// Created by User on 28/02/2019.
//

#include "headers.h"

void print_string(char *p_string, int p_count, bool p_reverse)
{
    if (p_reverse == true)
    {
        for (int k = p_count; k > 0; k--)
        {
            printf("%s %d\n", p_string, k);
        }
    }
    else
    {
        for (int k = 0; k < p_count; k++)
        {
            printf("%s %d\n", p_string, k);
        }
    }
}

void print_arguments(int argc, char *argv[])
{
    int counter;
    printf("Program Name Is: %s", argv[0]);
    if (argc == 1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name\n");
    if (argc >= 2) {
        printf("\nNumber Of Arguments Passed: %d", argc);
        printf("\n----Following Are The Command Line Arguments Passed----");
        for (counter = 0; counter < argc; counter++)
            printf("\nargv[%d]: %s", counter, argv[counter]);
        printf("\n");
    }
}

void print_environments(char **envp)
{
    printf("\nNow printing all system environments: \n");

    for (char **env = envp; *env != 0; env++) {
        char *thisEnv = *env;
        printf("%s\n", thisEnv);
    }

}

void exitprogram()
{
    printf("\nMain program waves goodbye\n");
}