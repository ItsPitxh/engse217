#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  // ✅ แก้ไข: เพิ่ม header file นี้

#define MAX_SIZE 100

int data[MAX_SIZE], temp[MAX_SIZE];
int N = 0;  // Number of elements

// ✅ ประกาศฟังก์ชันก่อนใช้
void displayData();
void generateRandomData();

// Function to generate random data
void generateRandomData() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        data[i] = rand() % 100;
    }
    printf("\nGenerated data: ");
    displayData();
}

// Function to display data
void displayData() {
    for (int i = 0; i < N; i++) {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

// 1️⃣ Insertion Sort
void insertionSort() {
    printf("\nInsertion Sort Steps:\n");
    for (int i = 1; i < N; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
        printf("Step %d: ", i);
        displayData();
    }
}

// 2️⃣ Bubble Sort
void bubbleSort() {
    printf("\nBubble Sort Steps:\n");
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
        printf("Step %d: ", i + 1);
        displayData();
    }
}

// 3️⃣ Quick Sort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] < pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        printf("Partition at index %d: ", pi);
        displayData();
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// 4️⃣ Heap Sort
void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        swap(&data[i], &data[largest]);
        heapify(n, largest);
    }
}

void heapSort() {
    printf("\nHeap Sort Steps:\n");
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(N, i);
        printf("Heapify Step %d: ", N - i);
        displayData();
    }
    for (int i = N - 1; i > 0; i--) {
        swap(&data[0], &data[i]);
        heapify(i, 0);
        printf("Heapify Step %d: ", N - i);
        displayData();
    }
}

// Main menu
void menu() {
    char choice;
    bool initialized = false;  // ✅ แก้ไข: เพิ่มตัวแปรควบคุมการเริ่มต้น

    printf("\nEnter the number of elements to generate (1-%d): ", MAX_SIZE);
    scanf("%d", &N);
    if (N <= 0 || N > MAX_SIZE) {
        printf("⚠️ Invalid input. Exiting program.\n");
        return;
    }
    generateRandomData();
    initialized = true;  // ✅ ใช้ true อย่างถูกต้อง

    do {
        printf("\n--- Sorting Program ---\n");
        printf("1. Generate new random data (Press 'r')\n");
        printf("2. Choose sorting method:\n");
        printf("   1) Insertion Sort\n");
        printf("   2) Bubble Sort\n");
        printf("   3) Quick Sort\n");
        printf("   4) Heap Sort\n");
        printf("0. Exit program\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'r') {
            generateRandomData();
        } else if (choice >= '1' && choice <= '4') {
            if (!initialized) {
                printf("⚠️ Please generate random data first! (Press 'r')\n");
                continue;
            }

            for (int i = 0; i < N; i++)  // Backup data before sorting
                temp[i] = data[i];

            switch (choice) {
                case '1':
                    insertionSort();
                    printf("\n📌 Insertion Sort result: ");
                    break;
                case '2':
                    bubbleSort();
                    printf("\n📌 Bubble Sort result: ");
                    break;
                case '3':
                    quickSort(0, N - 1);
                    printf("\n📌 Quick Sort result: ");
                    break;
                case '4':
                    heapSort();
                    printf("\n📌 Heap Sort result: ");
                    break;
            }
            displayData();

            for (int i = 0; i < N; i++)  // Restore original data
                data[i] = temp[i];

        } else if (choice != '0') {
            printf("⚠️ Invalid choice. Please try again.\n");
        }

    } while (choice != '0');

    printf("\n👋 Program exited.\n");
}

int main() {
    menu();
    return 0;
}