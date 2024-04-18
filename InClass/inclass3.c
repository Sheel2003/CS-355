#include <stdio.h>

int main() {
    float angle1, angle2, angle3;

    printf("Please enter the three angles of the triangle one by one:\n");
    scanf("%f %f %f", &angle1, &angle2, &angle3);

    if (angle1 + angle2 + angle3 == 180) {
        printf("The triangle is valid.\n");
    } else {
        printf("The triangle is not valid.\n");
    }

    return 0;
}
