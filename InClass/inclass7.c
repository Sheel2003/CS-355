#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(void) {
    // Declare a pointer to a directory stream and a pointer to a dirent structure
    DIR* dirp;
    struct dirent* direntp;

    // Open the directory "/home/fred"
    dirp = opendir(".");

    if (dirp != NULL) {
        
        while (1) {
            // Read the next directory entry
            direntp = readdir(dirp);

            // Check if there are no more entries and exit the loop if true
            if (direntp == NULL) break;

            // Print the name of the current directory entry
            printf("%s\n", direntp->d_name);
        }

        // Close the directory
        closedir(dirp);
    }

    // Exit the program
    return 0;
}
