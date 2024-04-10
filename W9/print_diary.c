// prints out contents of $HOME/.diary

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = ".diary";

int main(void) {
    // Create path $HOME/.diary

    // Get the environment variable for home
    char *home_path = getenv("HOME");

    if (home_path == NULL) {
        home_path = ".";
    }

    int path_length = strlen(home_path) + strlen(filename) + 2;

    char *pathname = malloc(path_length);

    snprintf(pathname, path_length, "%s/%s", home_path, filename);

    FILE *input = fopen(pathname, "r");

    if (input == NULL) {
        perror(pathname);
        return 1;
    }

    int letter;
    while ((letter = fgetc(input)) != EOF) {
        fputc(letter, stdout);
    }

    fclose(input);
    free(pathname);

    return 0;
}