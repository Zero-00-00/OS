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
    float avg_TAT=0, avg_WT=0;
    printf("Process     Burst time      WT      TAT\n");
    for (int j=0; j<n; j++) {
        TAT+=arr[j];
        avg_TAT+=TAT;
        avg_WT+=TAT-arr[j];
        printf("P%d             %d            %d      %d\n", j+1, arr[j], TAT-arr[j], TAT);
    }

    printf("The average Waiting time: %f\n", avg_WT/n);
    printf("The average Turn Around time: %f\n", avg_TAT/n);

    return 0;
}
