#define FORKING

#include <wait.h>
#include "headers.h"

int main(int argc, char *argv[], char **envp) {

#ifdef HELLOWORLD
    printf("Hello, World!\n");

#elif defined(STRINGS)

    char *string = "This is number:";
    print_string(string, 10, true);
    printf("\n");
    print_string(string, 10, false);

#elif defined(ARGUMENTPRINTING)

    //for when the program exits
    atexit(exitprogram);

    //printing the child and parent PID
    printf("Child is: %d & Parent is: %d \n", (int)getpid(),getppid());

    //printing the argv details passed to the program
    print_arguments(argc, argv);

    //printing the system environments
    print_environments(envp);

#elif defined(FORKING)
    execl("/bin/", "top -d 2 -n 10", (char *)NULL);

    pid_t pid = fork();

    //child process
    if (pid == 0)
    {
        int error = 0;
        char *args[] = { "ps", "-f" };
        error = execve(args[0], args, envp);
        if (error == -1)
            printf("Function was not executed correctly\n");
        exit(0);
    }
        //parent process
    else if (pid > 0)
    {
        //waiting for the child
        wait(NULL);
    }
    else
        printf("Error forking was not executed!!!\n");

#endif
    return 0;
}