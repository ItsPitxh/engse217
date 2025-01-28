#include <stdio.h>
#include <stdlib.h>

int *BA1, *BA2, *BA3; // Base addresses for arrays
int *p;               // Pointer for general use

// Create a 1D array
void Create1DArray(int size) {
    BA1 = (int *)malloc(size * sizeof(int));
}

// Assign a value to the 1D array
void A1(int i, int x) {
    p = BA1 + (i - 1);
    *p = x;
}

// Read a value from the 1D array
int ReadA1(int i) {
    p = BA1 + (i - 1);
    return (*p); // Return value in the array
}

// Create a 2D array
void Create2DArray(int u1, int u2) {
    int element, total_mem;
    element = (u1 + 1) * (u2 + 1); // Calculate total elements
    total_mem = element * sizeof(*BA2); // Calculate total memory
    BA2 = (int *)malloc(total_mem); // Allocate memory
}

// Assign a value to the 2D array
void A2(int i, int j, int x, int u2) {
    p = BA2 + ((i - 1) * (u2 + 1) + (j - 1));
    *p = x;
}

// Read a value from the 2D array
int ReadA2(int i, int j, int u2) {
    p = BA2 + ((i - 1) * (u2 + 1) + (j - 1));
    return (*p);
}

// Create a 3D array
void Create3DArray(int u1, int u2, int u3) {
    int element, total_mem;
    element = (u1 + 1) * (u2 + 1) * (u3 + 1); // Calculate total elements
    total_mem = element * sizeof(*BA3);      // Calculate total memory
    BA3 = (int *)malloc(total_mem);          // Allocate memory
}

// Assign a value to the 3D array
void A3(int i, int j, int k, int x, int u2, int u3) {
    p = BA3 + ((i - 1) * (u2 + 1) * (u3 + 1) + (j - 1) * (u3 + 1) + (k - 1));
    *p = x;
}

// Read a value from the 3D array
int ReadA3(int i, int j, int k, int u2, int u3) {
    p = BA3 + ((i - 1) * (u2 + 1) * (u3 + 1) + (j - 1) * (u3 + 1) + (k - 1));
    return (*p);
}

// Main function
int main() {
    printf("1-3 DIMENSION ARRAY FUNCTION...\n");

    // Create arrays
    Create1DArray(10);
    Create2DArray(10, 10);
    Create3DArray(10, 10, 10);

    // Using 1D array
    int i = 2;
    A1(i, 9);
    printf("\nA1(%d) = %d", i, ReadA1(i));

    // Using 2D array
    int j = 3;
    A2(i, j, 99, 10);
    printf("\nA2(%d,%d) = %d", i, j, ReadA2(i, j, 10));

    // Using 3D array
    int k = 5;
    A3(i, j, k, 999, 10, 10);
    printf("\nA3(%d,%d,%d) = %d", i, j, k, ReadA3(i, j, k, 10, 10));

    getchar(); // Wait for keyboard input

    // Free memory
    free(BA1);
    free(BA2);
    free(BA3);

    return 0;
}