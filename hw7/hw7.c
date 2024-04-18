#include <stdio.h>

#define DEVICENAME "/dev/random" // '/dev/random' is a special device file in Unix-like operating systems that serves as a source of random data. When programs read from /dev/random, they receive random data generated by the system's entropy pool, which collects unpredictable environmental noise from various sources like hardware interrupts and user input timings. Therefore, the program utilizes this file path to open and read from /dev/random, accessing its random data for various purposes.
#define len 10       // Define the length of data to be read as 10 bytes

int main(void) {          // Main function where the program execution starts
    size_t total = 0;      // Declare a variable to store the total bytes read
    char data[len];        // Declare an array to store the read data
    FILE *f = fopen(DEVICENAME, "r"); // Open the device file '/dev/random' in read mode and assign it to a file stream f

    if (NULL == f) // Check if the file opening was successful
        fprintf(stderr, "Failed to open '%s'.\n", DEVICENAME); // Print an error message if failed to open the device file
    else {
        total = fread(data, 1, sizeof(data), f); // Read data from the device file into the data array. Store the total number of bytes read in the variable total

        if (total == 0) { // Check if there was an error while reading
            fprintf(stderr, "Error reading from '%s'.\n", DEVICENAME); // Print an error message if failed to read from the device file
            fclose(f); // Close the file stream
        }

        for (int i = 0; i < len; i++) // Loop through each byte of the read data
            printf(" %d \n", data[i]); // Print each byte of the read data

        fclose(f); // Close the file stream
    }

    printf("Read %d bytes from '%s'.\n", (int)total, DEVICENAME);   // Print the total bytes read from the device file

    return 0; // Return 0 to indicate successful completion 
}