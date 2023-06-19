#include<stdio.h>

struct Process {
    int pid;        
    int btime; 
};

void calculateTimes(struct Process processes[], int n) {
    int wtime[n], tatime[n], i;
    
    wtime[0] = 0; 

    
    for ( i = 1; i < n; i++) {
        wtime[i] = processes[i - 1].btime + wtime[i - 1];
    }


    for ( i = 0; i < n; i++) {
        tatime[i] = processes[i].btime + wtime[i];
    }

    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].btime, wtime[i], tatime[i]);
    }

    
    float avg_wtime = 0, avg_tatime = 0;
    for (i = 0; i < n; i++) {
        avg_wtime += wtime[i];
        avg_tatime += tatime[i];
    }
    avg_wtime /= n;
    avg_tatime /= n;

    printf("Average Waiting Time: %.2f\n", avg_wtime);
    printf("Average Turnaround Time: %.2f\n", avg_tatime);
}


void sortProcesses(struct Process processes[], int n) {
	int i, j;
    for ( i = 0; i < n - 1; i++) {
        for (j= 0; j < n - i - 1; j++) {
            if (processes[j].btime > processes[j + 1].btime) {
                
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    
   
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].btime);
        processes[i].pid = i + 1;
    }

    
    printf("\nFirst-Come, First-Served (FCFS) Scheduling:\n");
    calculateTimes(processes, n);

    
    printf("\nShortest Job First (SJF) Scheduling:\n");
    sortProcesses(processes, n);
    calculateTimes(processes, n);

    return 0;
}

