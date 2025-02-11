#include <stdio.h>
#define size 15

int A[size][3];     //0->BT, 1->remaining time, 2->TAT

void RR(int A[size][3], int n, int q) {
    int i=0, flag=1, TAT=0;
    while(flag!=0) {
        if (A[i][1]-q>0) {
            A[i][1]-=q;
            TAT+=q;
        }
        else {
            TAT+=A[i][1];
            A[i][2]=TAT;
            A[i][1], flag=0;
        }
    }
}

int main() {
    int n, q;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", A[i][0]);
        A[i][1], A[i][2]=0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);
}