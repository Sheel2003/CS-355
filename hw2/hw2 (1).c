#include <stdio.h>

void fizzBuzz(int input) {
    for (int i = 0; i <= input; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else {
            printf("%d\n", i);
        }
    }
}

int main() {
    int input;

    printf("Please enter a number: ");
    scanf("%d", &input);

    fizzBuzz(input);

    return 0;
}
