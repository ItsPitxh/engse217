#include <stdio.h>

// Recursive function to calculate the factorial
int Factorial(int N) {
    int x, y;
    if (N == 0) {
        printf("Base Case: 0! = 1 .... Roll Back Point\n");
        return 1; // Base case: 0! = 1
    } else {
        x = N - 1;
        printf("N! = %d * %d! | Recursive Call: Factorial(%d)\n", N, x, x);
        y = Factorial(x); // Recursive call
        printf("%d! = %d * %d = %d | Returning to Previous Call\n", N, N, y, y * N);
        return N * y; // Recursive step
    }
}

int main() {
    int Number, ans;

    printf("RECURSIVE FACTORIAL PROGRAM\n");
    printf("===========================\n");

    // Continue asking for input until user enters -999 to end the program
    while (1) {
        printf("\nEnter a number (-999 to END): ");
        scanf("%d", &Number);

        if (Number == -999) {
            break; // Exit condition
        }

        if (Number >= 0) {
            printf("\nN! = N * (N-1)!\n");
            printf("------------------\n");
            ans = Factorial(Number); // Call the recursive factorial function
            printf("\nAnswer: %d! = %d\n", Number, ans);
            printf("------------------ Finished ------------------\n");
        } else {
            printf("Please enter a non-negative number.\n");
        }
    }

    return 0; // End of program
}