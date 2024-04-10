// removes public write from all files

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


void chmod_if_public_write(char *pathname) {
    struct stat s;
    if (stat(pathname, &s) != 0) {
        perror(pathname);
        exit(1);
    }

    mode_t mode = s.st_mode;

    if (!(mode & S_IWOTH)) {
        printf("%s is not publically writable\n", pathname);
        return;
    }

    printf("removing public write from %s\n", pathname);

    mode = mode & ~S_IWOTH;

    // Example
    // S_IWOTH = 0b0000000010
    // mode =     0b1111111111
    // ~S_IWOTH = 0b1111111101
    //  mode & ~S_IWOTH = 0b1111111101

    if (chmod(pathname, mode) != 0) {
        perror(pathname);
        exit(1);
    }

}

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_public_write(argv[arg]);
    }
    return 0;
}