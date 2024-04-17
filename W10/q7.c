#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_run(void *data) {
    while (1) {
        sleep(1);
        printf("feed mee!!!!\n");
    }
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    char line[1048];

    while (fgets(line, 1048, stdin) != NULL) {
        printf("you entered: %s", line);
    }

    pthread_join(thread, NULL);

    return 0;
}