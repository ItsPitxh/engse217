/* Program ASCENDING QUICK SORT can..
1. Random raw data into 1 dimension Array
2. Sorting and display detail of each result
3. Display final result
*/
#include <stdio.h>   //use printf
#include <stdbool.h> //use printf
#include <stdlib.h>  //use random
#include <time.h>    //use time
#define MaxData 100  // Define Max Data
int Data[MaxData],Data1[MaxData], Data2[MaxData];
int RawData[MaxData];
int i, N;


void PrepareRawData(int N)
{
    srand(time(NULL)); // for difference random number in rand()
    for (i = 1; i <= N; i++)
        Data[i] = 1 + rand() % 99; // random difference number 1..99

    for (i = 1; i <= N; i++)
        RawData[i] = Data[i]; // random difference number 1..99
        
}

void DispRawData(int N) {
    int i;
    for(i= 1; i<= N; i++) {
        printf(" %2d", RawData[i]);
    }
    printf("\n");
}

void DispData(int N)
{
    int i;
    for (i = 1; i <= N; i++)
        printf(" %2d", Data[i]);

    printf("\n");
}

void RawDataReplacement(int N) {
    int i;
    for (i = 1; i <= N; i++) {
        Data[i] = RawData[i];
    }
}
//QuickSort
void swapQS(int a, int b)
{
    int temp;
    temp = Data[a];
    Data[a] = Data[b];
    Data[b] = temp;
}
void QuickSort(int f, int r) // Recursive Fn.
{
    int f1, r1;
    bool direction;
    f1 = f;
    r1 = r; // keep old Front & Rear values
    direction = true;
    while (f != r)
    {
        if (Data[f] > Data[r]) // Ascending case
        {
            printf("%2d %2d : ", f, r);
            DispData(N);
            swapQS(f, r);
            printf("%2d %2d : ", f, r);
            DispData(N);
            direction = !direction; // change moving pointer direction
        }
        if (direction) // move r to left if TRUE
            r--;
        else
            f++; // move f right if FALSE
    }
    printf("k1=[%2d]--------------------------------------------------------\n", Data[f]); //
    // process in left hand
    if ((f > f1) && (f - 1 != f1))
        QuickSort(f1, f - 1); // recursive new position F&R
    // process in right hand
    if ((r < r1) && (r + 1 != r1))
        QuickSort(r + 1, r1); // recursive set new position F&R
}
//InsertionSort
void InsertionSort(int N)
{
    int i, j, temp;
    printf("---------------------------------------------------------------------\n");
    printf(" i ");
    for (i = 1; i <= N; i++)
        printf(" (%2d)", i);
    printf("\n");
    printf("---------------------------------------------------------------------\n");
    printf("%2d. ",0);
    DispData(N); //Show every step sorting
    for (i=1;i<N;i++) //Count i forward
    {
            if (Data[i + 1] < Data[i]) // If next data < previous data
            {
                temp = Data[i + 1]; // Keep insert data into temp
                Data[i + 1] = 0;
                j = i;                 // let counter j loop backward
                while (temp < Data[j]) // loop if temp remain < Data[j]
                {
                    Data[j + 1] = Data[j]; // Skip data forward to next block of
                    Data[j] = 0;
                    printf("%2d. ", i + 1);
                    DispData(N); // Show every time sorting
                    j = j - 1;   // count backward of j
                } // End while
                Data[j + 1] = temp; // Put temp into Data[j+1] finally
                printf("%2d. ", i + 1);
                DispData(N); // Show every time sorting
            } // end if
    } //ENd for
}


//BubbleSort
void BubbleSort(int N)
{
    int i, j, temp;
    printf("----------------------------------------------------------------\n");
    printf(" i ");
    for (i = 1; i <= N; i++)
        printf(" (%2d)", i);
    printf("\n");
    printf("----------------------------------------------------------------\n");
    for (i = 1; i <= N - 1; i++) // loop forward
    {
        if (Data[i] > Data[i + 1]) // if not true position
        {
            printf("%2d. ", i + 1);
            DispData(N);
            j = i + 1;                    // loop backward
            while (Data[j] < Data[j - 1]) // while if remain bubble
            {
                temp = Data[j - 1]; // swap data
                Data[j - 1] = Data[j];
                Data[j] = temp;
                j--; // count down j
                printf("%2d. ", i + 1);
                DispData(N);
            } // end while
        } // end if
    } // end for
}



//Heap
void DispHeapData(int Data[], int out) // Out is point of Outputted Number backward
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if (i < out)
            printf("%2d ", Data[i]); // Show 2 width of number
        else
            printf("[%2d] ", Data[i]); // Show [ ] if it's Output
    }
    printf("\n");
}

void swap(int a, int b)
{
    int temp;
    temp = Data2[a];
    Data2[a] = Data2[b];
    Data2[b] = temp;
}
int Maximum(int a, int b) // Fine Maximum from 2 Data
{
    if (a > b)
        return (a);
    else
        return (b);
}
void AdjustTree(int LastNode)
{
    int i, Max, lson, rson, son;
    bool result;
    i = 1;
    result = false; // False is NOT Finish Adjustment yet
    while (!result)
    {
        lson = (2 * i);     // Calculate LSon
        rson = (2 * i) + 1; // Calculate RSon
        son = 0;            // Set default Son
        if (lson == LastNode)
        {
            son = 1;
            if (Data2[i] < Data2[lson]) // Check Father Data < LSon data ?
            {
                swap(i, lson);
                DispHeapData(Data2, LastNode + 1); // Show each step result
            }
            result = true; // Finish Adjustment
        }
        if (rson <= LastNode)
        {
            son = 2;
            Max = Maximum(Data2[lson], Data2[rson]); // Find Maximum Data
            if (Data2[i] < Max)                      // Check Father Data < Max ?
            {
                if (Max == Data2[lson]) // Max == Data Lson?
                {
                    swap(i, lson);
                    DispHeapData(Data2, LastNode + 1); // Show each step result
                    if (rson == LastNode)          // Check for Last Node
                        result = true;             // Finish Adjustment
                    else
                        i = lson; // Let i follow to LSon
                }
                else // if Data RSon is Maximum
                {
                    swap(i, rson);
                    DispHeapData(Data2, LastNode + 1); // Show each step
                    if (rson == LastNode)          // Check for Last Node
                        result = true;             // Finish Adjustment
                    else
                        i = rson; // Let i follow to RSon
                }
            }
            else
                result = true; // Finish Adjustment
        }
        if (son == 0)
            result = true; // Finish Adjustment
    } // End While
    printf("---------------------------------------------------AdjustTree Finished at N=%d \n", LastNode);
} // End Fn.
void CreateHeapTree() // Create form Data1 into Data2
{
    int i, j, k, father;
    bool result;
    // Craete Heap Tree
    Data2[1] = Data[1];    // First node of Heap Tree
    DispHeapData(Data2, N + 1); // Show each step result
    for (i = 2; i <= N; i++)
    {
        Data2[i] = Data[i];
        DispHeapData(Data2, N + 1); // Show each step result
        result = true;
        j = i; // set backward counter start here
        while (result)
        {
            father = j / 2;                            // Calculate Father
            if ((Data2[j] > Data2[father]) && (j > 1)) // Heap tree adjusting
            {
                swap(j, father);
                DispHeapData(Data2, N + 1); // Show each step result
                j = father;             // Let j follow to new Father
                result = true;
            }
            else
                result = false;
        } // End While
    } // End for
    printf("---------------------------------------------------CreateHeap Tree Finished \n");
    for (k = 1; k <= N; k++) // Display Array subscript
        printf("(%d) ", k);
    printf("\n");
    for (i = N; i > 1; i--)
    {
        swap(1, i);         // Output Root Node
        DispHeapData(Data2, i); // Show each step result
        AdjustTree(i - 1);  // Call Adjust Heap Tree
    } // End for
} // End Fn.
// Main menu
void menu()
{
    char choice;
    do
    {
        printf("Raw Data: ");
        DispRawData(N);
        printf("[r] Generate new data\n");
        printf("[1] Insertion Sort\n");
        printf("[2] Bubble Sort\n");
        printf("[3] Quick Sort\n");
        printf("[4] Heap Sort\n");
        printf("[0] Exit program\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
            if ((choice <= '4' && choice >= '1') || choice == 'r') 
            {
                switch (choice)
                {
                    case 'r': 
                        system("clear");
                        system("clear");
                        printf("Old Data: ");
                        DispData(N);
                        PrepareRawData(N);
                        break;
    
                    case '1':
                        system("clear");
                        system("clear");
                        InsertionSort(N);
                        printf("sorted data: ");
                        DispData(N);
                        break;
                    case '2':
                        system("clear");
                        system("clear");
                        BubbleSort(N);
                        printf("sorted data: ");
                        DispData(N);
    
                        break;
                    case '3':
                        system("clear");
                        system("clear");
                        QuickSort(0, N);
                        printf("sorted data: ");
                        DispData(N);
                        break;
                    case '4':
                        system("clear");
                        system("clear");
                        CreateHeapTree();
                        printf("sorted data: ");
                        DispHeapData(Data2, 1);
                        break;
                }
            }
            else {
                system("clear");
                system("clear");
            }
        RawDataReplacement(N);
    } while (choice != '0');
    system("clear");
    printf("\n👋 Program exited.\n");
}

int main()
{
    system("clear");
    system("clear");
    printf("Enter data size: ");
    scanf(" %d", &N);
    system("clear");
    system("clear");
    PrepareRawData(N);
    
    menu();
    getchar();
    return (0);
} // End Main