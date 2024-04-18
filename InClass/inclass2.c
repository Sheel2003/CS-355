#include <stdio.h>

int main() {
    float basicSalary, grossSalary, da, hra;
    
    printf("Please enter the basic salary: ");
    scanf("%f", &basicSalary);
    
    if (basicSalary <= 10000) {
        da = 0.08 * basicSalary;
        hra = 0.2 * basicSalary;
    } else if (basicSalary <= 20000) {
        da = 0.09 * basicSalary;
        hra = 0.25 * basicSalary;
    } else {
        da = 0.95 * basicSalary;
        hra = 0.3 * basicSalary;
    }
    
    grossSalary = basicSalary + da + hra;
    
    printf("Basic Salary: %.2f\n", basicSalary);
    printf("DA: %.2f\n", da);
    printf("HRA: %.2f\n", hra);
    printf("Gross Salary: %.2f\n", grossSalary);

    return 0;
}
