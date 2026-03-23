#include <stdio.h>

int main()
{
    int i, j = 0, n;
    int burst[10], wait[10], turn[10];
    float w = 0, t = 0;

    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    burst[0] = 0;

    printf("Enter the burst time for each process:\n");
    for (i = 1; i <= n; i++) {
        printf("P%d: ", i);
        scanf("%d", &burst[i]);
    }

    printf("\n\nGantt Chart\n");
    printf("  ");
    for (i = 1; i <= n; i++)
        printf("| P%d\t", i);
    printf("|\n  ");

    for (i = 0; i <= n; i++) {
        j = j + burst[i];
        wait[i + 1] = j;
        turn[i] = j;
        printf("%d\t\t", j);
    }

    for (i = 1; i <= n; i++)
        w = w + wait[i];
    for (i = 0; i <= n; i++)
        t = t + turn[i];

    w = w / n;
    t = t / n;

    printf("\nAverage Waiting Time: %.2f", w);
    printf("\nAverage Turnaround Time: %.2f\n", t);

    return 0;
}
