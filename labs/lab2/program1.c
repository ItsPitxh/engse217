#include <stdio.h>
#define MaxStack 6 // Define max stack size

int stack[MaxStack] = {0}; // Initialize stack to zero
int SP = -1; // Stack pointer starts at -1 (empty)
char status = 'N'; // Status: N = Normal, O = Overflow, U = Underflow

void push(int x) {
    if (SP >= MaxStack - 1) { // Check for overflow
        printf("| !!OVERFLOW!! |\n");
        status = 'O';
    } else {
        SP++;
        stack[SP] = x;
        printf("Pushed: %d\n", x);
    }
}

int pop() {
    if (SP < 0) { // Check for underflow
        printf("| !!UNDERFLOW!! |\n");
        status = 'U';
        return -1; // Return an invalid value to indicate underflow
    } else {
        int x = stack[SP];
        stack[SP] = 0; // Clear the value
        SP--;
        return x;
    }
}

void showAllStack() {
    printf("\n--- Stack Status ---\n");
    printf("Max Size: %d\n", MaxStack);
    printf("Current SP: %d\n", SP);
    printf("Status: %c\n", status);
    printf("Stack Contents: ");
    for (int i = 0; i < MaxStack; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n--------------------\n");
}

int main() {
    int x;
    char choice;
    printf("STACK PROGRAM\n");
    printf("===================\n");

    while (status == 'N') {
        printf("[1 = PUSH, 2 = POP] : ");
        scanf(" %c", &choice); // Read user choice
        switch (choice) {
            case '1':
                printf("Enter a number to push: ");
                scanf("%d", &x);
                push(x);
                showAllStack();
                break;
            case '2':
                x = pop();
                if (status != 'U') { // Only show valid popped value
                    printf("Popped: %d\n", x);
                }
                showAllStack();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    printf("Program terminated.\n");
    return 0;
}