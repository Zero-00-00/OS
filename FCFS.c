#include <stdio.h>

int main() {
    int n;
    printf("\n---------------------------------------- First Come First Serve ----------------------------------------\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int TAT=0;
    printf("Process     Burst time      TAT      WT\n");
    for (int j=0; j<n; j++) {
        TAT+=arr[j];
        printf("P%d             %d            %d      %d\n", j+1, arr[j], TAT, TAT-arr[j]);
    }
}
