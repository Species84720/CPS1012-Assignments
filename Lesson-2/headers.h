//
// Created by User on 28/02/2019.
//

#ifndef LESSON_2_HEADERS_H
#define LESSON_2_HEADERS_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_string(char *p_string, int p_count, bool p_reverse);
void print_arguments(int argc, char *argv[]);
void print_environments(char **envp);
void exitprogram();

#endif //LESSON_2_HEADERS_H
