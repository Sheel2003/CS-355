#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

// Function prototype for do_ls
void do_ls(char [], bool, bool);

// Comparison function for sort
int compareChars(const void *a, const void *b) { 
    const char *string1 = *(const char **)a;
    const char *string2 = *(const char **)b;
    return strcmp(string1, string2);
}

// Main Method
int main(int argc, char *argv[]) {
    // Boolean comparison variables for -s and -r 
    bool r = false;   
    bool s = false;
    
    if (argc == 1) {
        do_ls(".", s, r); // List current directory by default
    }
    else if (argc == 2) {
        int len = strlen(argv[1]);
        char argument_1[len];
        strcpy(argument_1, argv[1]);
        
        if (argument_1[0] != '-') { // If argument is not a flag
            printf("%s:\n\n", argument_1);
            do_ls(argument_1, s, r); // List specified directory
        } else {
            if (argv[1][1] == 's') {
                s = true;
            }
            if (argv[1][1] == 'r') {
                r = true;
            }
            printf("%s:\n\n", argument_1);
            do_ls(".", s, r); // List current directory with specified options
        }
    } else {
        int len = strlen(argv[1]);
        char argument_1[len];
        strcpy(argument_1, argv[1]);
        len = strlen(argv[2]);
        char argument_2[len];
        strcpy(argument_2, argv[2]);
        
        if (argv[1][1] == 's') {
            s = true;
        }
        if (argv[1][1] == 'r') {
            r = true;
        }
        
        printf("%s ", argument_1);
        printf("%s :\n\n", argument_2);
        do_ls(argument_2, s, r); // List specified directory with specified options
    }
}

// ls method
void do_ls(char dirname[], bool s, bool r) {
    DIR *dir_ptr;
    struct dirent *direntp;

    char* dir_array[200];
    int size = 0;

    if ((dir_ptr = opendir(dirname)) == NULL)
        fprintf(stderr, "myls1: cannot open %s\n", dirname);
    else {
        while ((direntp = readdir(dir_ptr)) != NULL) {
            dir_array[size] = direntp->d_name;
            size++;
        }
        closedir(dir_ptr);

        if (s == true) {
            printf("%s\n", "Files displayed in order");
            printf("%s\n\n", "_________________________");
            qsort(dir_array, size, sizeof(char*), compareChars);
        }
        if (r == true) {
            printf("%s\n", "Files displayed in reverse order ");
            printf("%s\n\n", "___________________________________");
            qsort(dir_array, size, sizeof(char*), compareChars);
            for (int i = size - 1; i >= 0; i--) {
                printf("%s\n", dir_array[i]);
            }
        } else {
            for (int i = 0; i < size; i++) {
                printf("%s\n", dir_array[i]);
            }
        }
    }
}
