#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [r|w|rw]\n", argv[0]);
        return 1; 
    }

    int fd, inode, mode;
    char *mode_arg = argv[1];

    if (strcmp(mode_arg, "r") == 0)
        mode = O_RDONLY;
    else if (strcmp(mode_arg, "w") == 0)
        mode = O_WRONLY;
    else if (strcmp(mode_arg, "rw") == 0)
        mode = O_RDWR;
    else {
        fprintf(stderr, "Invalid mode argument. Use [r|w|rw]\n");
        return 1;
    }

    fd = open("hw5.c", mode);
    if (fd < 0) {
        perror("Error opening the file");
        return 1; // Exit the program if file opening failed
    }

    struct stat file_stat;
    int ret;
    ret = fstat(fd, &file_stat);
    if (ret < 0) {
        perror("Error getting file stat");
        close(fd); // Close the file descriptor before exiting
        return 1; // Exit the program if getting file stat failed
    }
    
    inode = file_stat.st_ino; // inode now contains inode number of the file
    printf("Inode number of the file: %ld\n", (long)inode); // Print the inode number
    close(fd); // Close the file descriptor after usage
    return 0;
    // Done!
}
