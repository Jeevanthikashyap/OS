#include <stdio.h>

// Function to calculate waiting time and turnaround time
void calculateTimes(int processes[], int burstTime[], int priority[], int n, int preemptive, float *avgWaitingTime, float *avgTurnaroundTime) {
    int currentTime = 0;
    int completed = 0;
    int waitingTime[n], turnaroundTime[n];
    int i;

    for ( i = 0; i < n; i++) {
        waitingTime[i] = 0;
        turnaroundTime[i] = 0;
    }

    while (completed < n) {
        int highestPriority = -1;
        int selectedProcess = -1;

        for (i = 0; i < n; i++) {
            if (burstTime[i] <= 0)
                continue;

            if (preemptive) {
                if (highestPriority == -1 || priority[i] < highestPriority) {
                    highestPriority = priority[i];
                    selectedProcess = i;
                }
            } else {
                if (priority[i] < highestPriority || highestPriority == -1) {
                    highestPriority = priority[i];
                    selectedProcess = i;
                }
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
            continue;
        }

        burstTime[selectedProcess]--;

        if (burstTime[selectedProcess] == 0) {
            completed++;
            waitingTime[selectedProcess] = currentTime - priority[selectedProcess];
            turnaroundTime[selectedProcess] = currentTime;
        }

        currentTime++;
    }

    *avgWaitingTime = 0;
    *avgTurnaroundTime = 0;

    printf("\nProcess\t\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
        *avgWaitingTime += waitingTime[i];
        *avgTurnaroundTime += turnaroundTime[i];
    }

    *avgWaitingTime /= n;
    *avgTurnaroundTime /= n;
}

int main() {
    int n,i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], priority[n];

    for ( i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter Burst Time: ");
        scanf("%d", &burstTime[i]);
        printf("Enter Priority: ");
        scanf("%d", &priority[i]);
    }

    int choice;

    printf("\nSelect Scheduling Type:\n");
    printf("1. Priority (Preemptive)\n");
    printf("2. Priority (Non-Preemptive)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    float avgWaitingTime, avgTurnaroundTime;

    switch (choice) {
        case 1:
            calculateTimes(processes, burstTime, priority, n, 1, &avgWaitingTime, &avgTurnaroundTime);
            break;
        case 2:
            calculateTimes(processes, burstTime, priority, n, 0, &avgWaitingTime, &avgTurnaroundTime);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    return 0;
}
