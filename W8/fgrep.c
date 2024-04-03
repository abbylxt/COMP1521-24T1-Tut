#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH  8192

void search_file(FILE *file, char *needle) {
    char line[MAX_LENGTH];
    char line_no = 0;
    while (fgets(line, MAX_LENGTH, file)) {
        if (strstr(line, needle) != NULL) {
            fputc(line_no);
            fputs(line);
        }
        line_no++;
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Usage: %s <pattern> <file>...\n", argv[0]);
        exit(1);
    }
    if (argc == 2) {
        search_file(stdin, argv[1]);
    } else {
        // argc >=3
        // argv[0] = program name
        // argv[1] = string
        // argv[2...] = file names
        int i = 2;
        while (i < argc) {
            File* input = fopen(argv[i], "r");
            if (input == NULL) {
                perror("Error: ");
                exit(2);
            }
            search_file(input, argv[1]);
            fclose(input);
            i++;
        }
    }
}