#include <stdio.h>
#define size 15

int A[size][2];  // A[i][0] = burst time, A[i][1] = process ID

void swap(int* x, int* a, int* y, int* b) {
    int temp = *x;
    *x = *y;
    *y = temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int part(int A[size][2], int p, int r) {
    int x = A[r][0];  // Pivot is the burst time of the last element
    int i = p - 1;

    for(int j = p; j < r; j++) {
        if (A[j][0] <= x) {  // Sort by burst time (ascending)
            i++;
            swap(&A[i][0], &A[i][1], &A[j][0], &A[j][1]);
        }
    }
    swap(&A[i + 1][0], &A[i + 1][1], &A[r][0], &A[r][1]);  // Move pivot to correct position
    return i + 1;  // Return pivot index
}

void qsort(int A[size][2], int p, int r) {
    if (p < r) {
        int q = part(A, p, r);
        qsort(A, p, q - 1);
        qsort(A, q + 1, r);
    }
}

int main() {
    int n;
    printf("\n---------------------------------------- Shortest Job First ----------------------------------------\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &A[i][0]);
        A[i][1] = i + 1;  // Assign process ID
    }

    qsort(A, 0, n - 1);  // Sort based on burst time

    int TAT = 0;  // Turnaround time
    float avg_TAT=0, avg_WT=0;
    printf("Process     Burst time      TAT      WT\n");
    for (int j = 0; j < n; j++) {
        TAT += A[j][0];  // Add burst time to Turnaround time
        avg_TAT+=TAT;
        int WT = TAT - A[j][0];  // Waiting time = TAT - Burst time
        avg_WT+=WT;
        printf("P%d             %d            %d      %d\n", A[j][1], A[j][0], TAT, WT);
    }

    printf("The average Waiting time: %f\n", avg_WT/n);
    printf("The average Turn Around time: %f\n", avg_TAT/n);

    return 0;
}
