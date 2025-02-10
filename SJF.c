#include <stdio.h>
#define size 15

int A[size][2];

void swap(int* x, int* a, int* y, int* b) {
    int temp = *x;
    *x = *y;
    *y = temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int part(int A[size][2], int p, int r) {
    int x = A[p][1];
    int i = p;
    for(int j = p+1; j < r+1; j++) {
        if (A[j][0] >= x) {
            i += 1;
            swap (&A[i][0], &A[i][1], &A[j][0], &A[j][1]);
        }
    }
    swap(&A[i][0], &A[i][1], &A[p][0], &A[p][1]);            //swap the pivot with the element in A[i]
    return i;
}

int qsort(int A[size][2], int p, int r) {
    int q;
    if (p < r) {
        q = part(A, p, r);
        qsort(A, p, q-1);
        qsort(A, q+1, r);
    }
}

int main() {
    int n;
    printf("\n---------------------------------------- Shortest Job First ----------------------------------------\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &A[i][0]);
        A[i][1]=i+1;
    }

    qsort(A, 0, n-1);

    int TAT=0;
    printf("Process     Burst time      TAT      WT\n");
    for (int j=0; j<n; j++) {
        TAT+=A[j][0];
        printf("P%d             %d            %d      %d\n", A[j][1], A[j][0], TAT, TAT-A[j][0]);
    }
}
