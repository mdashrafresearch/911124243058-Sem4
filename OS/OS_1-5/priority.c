#include <stdio.h>

struct process {
    int id;
    int bt;       // Burst Time
    int wt;       // Waiting Time
    int tat;      // Turnaround Time
    int priority;
};

void findWaitingTime(struct process proc[], int n)
{
    proc[0].wt = 0;
    for (int i = 1; i < n; i++)
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;
}

void findTurnaroundTime(struct process proc[], int n)
{
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].wt + proc[i].bt;
}

void findAverageTimes(struct process proc[], int n)
{
    int totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        totalWT  += proc[i].wt;
        totalTAT += proc[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTAT / n);
}

void priorityScheduling(struct process proc[], int n)
{
    // Sort processes by priority (ascending = higher priority first)
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                temp    = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].id, proc[i].bt, proc[i].priority,
               proc[i].wt, proc[i].tat);
    }

    findAverageTimes(proc, n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nEnter Burst Time and Priority for Process P%d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &proc[i].bt);
        printf("Priority: ");
        scanf("%d", &proc[i].priority);
    }

    priorityScheduling(proc, n);

    return 0;
}
