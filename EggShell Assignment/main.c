#include "header.h"

int main(int argc, char *argv[], char **envp) {
    tiny_shell(envp);
    return 0;
}

void signalHandler(int sig)
{
    //resetting signal
    signal(SIGINT, signalHandler);

    //getting the pid of the current process
    if (killPID != 0) {
        kill(killPID, SIGINT);
        fflush(stdout);
    }
}