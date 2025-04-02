#include <stdio.h>
#define size 15

int A[size][3];     // 0->BT, 1->remaining time, 2->TAT

void RR(int A[size][3], int n, int q) {
    int flag = 1, TAT=0;
    while (flag != 0) {
        flag = 0;  // Reset flag to 0 (exit condition)
        for (int i = 0; i < n; i++) {
            if (A[i][1] > 0) {  // Process is still not complete
                flag = 1;  // Set flag to 1 indicating at least one process is still running
                if (A[i][1] > q) {
                    A[i][1] -= q;
                    TAT += q;  // Add the time quantum to TAT
                } else {
                    TAT += A[i][1];  // Add the remaining burst time to TAT
                    A[i][2]=TAT;
                    A[i][1] = 0;  // Mark this process as completed
                }
            }
        }
    }
}

int main() {
    int n, q;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &A[i][0]);
        A[i][1] = A[i][0];  // Initialize remaining time to burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);

    RR(A, n, q);

    printf("Process     Burst time      TAT      WT\n");
    for (int j = 0; j < n; j++) {
        int WT = A[j][2] - A[j][0];  // Waiting time = Turnaround Time - Burst Time
        printf("P%d             %d            %d      %d\n", j + 1, A[j][0], A[j][2], WT);
    }

    return 0;
}
