#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, n;
    int burst[10], wait[10], turn[10];
    float w = 0, t = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &burst[i]);
    }

    // FCFS calculations
    wait[0] = 0;
    turn[0] = burst[0];

    for (i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + burst[i - 1];
        turn[i] = wait[i] + burst[i];
    }

    printf("\nGantt Chart:\n\n");
    for (i = 0; i < n; i++)
        printf("\tP%d\t|", i + 1);

    printf("\n0");
    for (i = 0; i < n; i++)
        printf("\t%d", turn[i]);

    for (i = 0; i < n; i++)
    {
        w += wait[i];
        t += turn[i];
    }

    w = w / n;
    t = t / n;

    printf("\n\nAverage Waiting Time = %.2f", w);
    printf("\nAverage Turnaround Time = %.2f\n", t);

    return 0;
}
