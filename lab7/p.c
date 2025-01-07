#include <stdio.h>

// Recursive function to calculate power
long long power(int base, int exponent) {
    if (exponent == 0) {
        return 1; // Base case: any number raised to the power of 0 is 1
    } else {
        long long previous = power(base, exponent - 1); // Recursive call
        long long result = base * previous;
        printf("Step: %d^%d = %lld\n", base, exponent, result); // Display each step
        return result;
    }
}

int main() {
    int base, exponent;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    printf("\nCalculation steps:\n");
    long long result = power(base, exponent); // Call recursive function
    printf("\nFinal Result: %d^%d = %lld\n", base, exponent, result);

    return 0;
}