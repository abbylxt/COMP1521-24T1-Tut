#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH  8192

int main(int argc, char *argv[]) {
    // This program should only run for argc == 2
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    // Open the given file in reading mode
    File* input = fopen(argv[1], "r");
    if (input == NULL) {
        // Print "Error: " + the error message cooresponding the error number set by fopen
        perror("Error: ");
        exit(2);
    }
    char first_line[MAX_LENGTH];
    if (fgets(first_line, MAX_LENGTH, input) == NULL) {
        fprintf(stderr, "Cannot read first line");
        exit(3);
    }
    // Print the first line in standard output
    fprintf(stdout, "%s", first_line);
    // Remember to always close your files after you finish using them!!!
    fclose(input);
}