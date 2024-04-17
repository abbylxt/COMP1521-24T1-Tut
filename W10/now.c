#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// extern means the variable is defined somewhere else.
// In this case, the variable is defined by the system environment.
extern char **environ;

// Spawns a process and waits for it to die.
// Input is the argv array of the process function.
void spawn_and_wait(char **args)
{
    pid_t *pid;
    int spawn_status = posix_spawn(&pid, args[0], NULL, NULL, args, environ);

    if (spawn_status != 0) {
        errno = spawn_status;
        perror("posix_spawn");
        exit(1);
    }

    int spawn_exit_status;

    if (waitpid(pid, &spawn_exit_status, 0) == -1) {
        perror("waitpid");
        exit(2);
    }
    
}

int main(int argc, char *argv[])
{
    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn_and_wait(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    spawn_and_wait(time_argv);

// usr/bin == bin
    char *user_argv[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait(user_argv);

    char *hostname_argv[] = {"/usr/bin/hostname", "-f", NULL};
    spawn_and_wait(hostname_argv);

    char *working_dir_argv[] = {"/bin/realpath", ".", NULL};
    spawn_and_wait(working_dir_argv);
}