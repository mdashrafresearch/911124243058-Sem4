#include <stdio.h>
#include <stdlib.h>

int p, r, m, z, k, buf;
int a[10], avail[10], max[10][10], alloc[10][10], need[10][10];
int i, j, top;

void get()
{
    printf("\nENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &p);

    printf("\nENTER THE NUMBER OF RESOURCE TYPES: ");
    scanf("%d", &r);

    for (j = 1; j <= r; j++) {
        printf("\nENTER THE NUMBER OF RESOURCES FOR TYPE %d : ", j);
        scanf("%d", &avail[j]);
    }

    for (i = 1; i <= p; i++) {
        printf("\nENTER THE MAXIMUM NUMBER OF RESOURCES REQUIRED FOR PROCESS %d:\n", i);
        for (j = 1; j <= r; j++) {
            printf("\nFor Resource type %d :", j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nENTER THE ALLOCATED INSTANCES:\n");
    for (i = 1; i <= p; i++) {
        printf("\nPROCESS %d:", i);
        printf("\n-------------");
        for (j = 1; j <= r; j++) {
            printf("\nResource Type - %d :", j);
            scanf("%d", &m);
            if (m <= avail[j]) {
                alloc[i][j] = m;
                avail[j] = avail[j] - m;
            } else {
                printf("\nALLOCATION EXCEEDS MAXIMUM. U CAN'T ALLOCATE IT.");
            }
        }
    }
}

void disp1()
{
    printf("\nNEEDED RESOURCES:");
    printf("\n-----------------");
    for (i = 1; i <= p; i++) {
        printf("\nProcess %d:\t", i);
        for (j = 1; j <= r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf(" %d", need[i][j]);
        }
    }
}

void seqnc()
{
    top = 1;
    while (top <= p) {
        for (i = 1; i <= p; i++) {
            buf = 0;
            z = 0;
            for (j = 1; j <= r; j++) {
                z = z + need[i][j];
                if (need[i][j] <= avail[j])
                    buf++;
            }
            if (buf == r && z != 0) {
                a[top] = i;
                top++;
                for (k = 1; k <= r; k++) {
                    avail[k] = avail[k] + alloc[i][k];
                    need[i][k] = 0;
                }
            }
        }
    }
}

void disp2()
{
    printf("\nThe Sequence of allocation to the processes:");
    for (i = 1; i <= p; i++)
        printf(" %d", a[i]);
    printf("\n");
}

int main()
{
    get();
    disp1();
    seqnc();
    disp2();
    return 0;
}
