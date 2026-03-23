#include <stdio.h>

int main()
{
    int b[10], temp, i, j, n;
    int wait[10], burst[10], turn[10];
    float w = 0, t = 0;

    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    burst[0] = 0;
    b[0] = 0;

    printf("Enter the burst time for each process:\n");
    for (i = 1; i <= n; i++) {
        printf("P%d: ", i);
        scanf("%d", &burst[i]);
        b[i] = burst[i];
    }

    // Sort burst times in ascending order (SJF)
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (b[i] > b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("\nGantt Chart\n  ");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (b[i] == burst[j])
                printf("| P%d\t", j);
        }
    }

    printf("|\n  ");

    j = 0;
    for (i = 0; i <= n; i++) {
        j = j + b[i];
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
