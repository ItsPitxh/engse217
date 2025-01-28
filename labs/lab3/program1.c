#include <stdio.h>
#define N 5 // Define max queue size

int Q[N] = {0}; // Initialize queue to zeros
int F = -1, R = -1; // Front and rear pointers start at -1 (empty)
char status = 'N'; // Status: N = Normal, O = Overflow, U = Underflow

void insertQ(int y) {
    if (R == N - 1) { // Check for overflow
        printf("!! OVERFLOW! !!...\n");
        status = 'O';
    } else {
        if (F == -1) F = 0; // Initialize front if inserting first element
        R++;
        Q[R] = y;
        printf("Inserted: %d\n", y);
    }
}

int deleteQ() {
    if (F == -1 || F > R) { // Check for underflow
        printf("!! UNDERFLOW! !!...\n");
        status = 'U';
        return -1; // Return invalid value for underflow
    } else {
        int y = Q[F];
        Q[F] = 0; // Clear the value
        F++;
        if (F > R) { // Reset queue if it becomes empty
            F = -1;
            R = -1;
        }
        return y;
    }
}

void ShowAllQueue() {
    printf("\n--- Queue Status ---\n");
    printf("Max Size: %d\n", N);
    printf("Front: %d, Rear: %d\n", F, R);
    printf("Status: %c\n", status);
    printf("Queue Contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main() {
    int x;
    char choice;
    
    printf("QUEUE PROGRAM\n");
    
    while (status == 'N') {
        printf("[1 = INSERT, 2 = DELETE]: ");
        scanf(" %c", &choice); // Read user choice
        
        switch (choice) {
            case '1':
                printf("Enter a number to insert: ");
                scanf("%d", &x);
                insertQ(x);
                ShowAllQueue();
                break;
            case '2':
                x = deleteQ();
                if (status != 'U') { // Only show valid dequeued value
                    printf("Dequeued: %d\n", x);
                }
                ShowAllQueue();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    printf("Program terminated.\n");
    return 0;
}