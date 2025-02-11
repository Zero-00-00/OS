#include <stdio.h>
#define size 15

int A[size][3];     //0->BT, 1->remaining time, 2->TAT

void RR(int A[size][3], int n, int q) {
    int flag=1, TAT=0;
    while(flag!=0) {
        for(int i=0; i<n; i++) {
            if (A[i][1]-q>0) {
                A[i][1]-=q;
                TAT+=q;
                flag=1;
            }
            else if (A[i][1]!=0) {
                TAT+=A[i][1];
                A[i][2]=TAT;
                A[i][1]=0;
            }
            else {
                if (i!=n-1)
                flag=0;
            }
        }
    }
}

int main() {
    int n, q;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &A[i][0]);
        A[i][1]=A[i][0];
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);

    RR(A, n, q);

    printf("Process     Burst time      TAT      WT\n");
    for (int j=0; j<n; j++) {
        printf("P%d             %d            %d      %d\n", j+1, A[j][0], A[j][2], A[j][2]-A[j][0]);
    }
}