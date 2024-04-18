#include <stdio.h>
#include <ctype.h>

void count(char *str, int *vowelCount, int *consonantCount) {
    while (*str) {
        char currentChar = *str;

        if (isalpha(currentChar)) {
            currentChar = tolower(currentChar);
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
                (*vowelCount)++;
            } else {
                (*consonantCount)++;
            }
        }
        str++;
    }
}

int main() {
    char inputString[100];
    int vowelCount = 0, consonantCount = 0;

    // Get user input using scanf and [^ is to use for Indicates the start of a character set and ^ Inverts the character set, meaning it will match any character not in the specified set.
    printf("Enter a string: ");
    scanf("%[^\n]", inputString);

    count(inputString, &vowelCount, &consonantCount);

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}
