#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *message = data;
    while (1) {
        printf("%s", message);
    }

    return NULL;
}

int main(void) {
    char *message_thread = "Hello\n";

    pthread_t thread;
    pthread_create(&thread,
                   NULL,
                   thread_run,
                   message_thread);

    while (1) {
        printf("class\n");
    }

    return 0;
}