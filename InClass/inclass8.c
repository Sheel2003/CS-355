/* filesize.c - prints size of a file in the current directory */
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat infobuf; /* place to store info */

    if (stat("inclass6.c", &infobuf) == -1) /* get info */
        perror("Error getting file information");
    else
        printf("The size of the file is %ld bytes\n", infobuf.st_size);

    return 0;
}
