#include <stdio.h>

#define MAX_STRING_LENGTH 50
#define NUM_STRINGS 10

int main() {
    char strings[NUM_STRINGS][MAX_STRING_LENGTH];

    printf("Please enter 10 strings:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    printf("\nStrings in reverse order:\n");
    for (int i = NUM_STRINGS - 1; i >= 0; i--) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
