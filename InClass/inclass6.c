#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *folder;           // Pointer to work with a folder/directory
    struct dirent *entry;  // Structure to work with each file in the directory
    int files = 0;         // Variable to keep track of the number of files

    folder = opendir("..");  // Open the parent directory .. denotes the parent directory
    
    if (folder == NULL) {
        perror("Unable to read directory");
        return(1);
    }

    while ((entry = readdir(folder))) {
        files++;
        printf("File %3d: %s\n", files, entry->d_name);
    }

    closedir(folder);  // Close the directory

    return(0);
}
