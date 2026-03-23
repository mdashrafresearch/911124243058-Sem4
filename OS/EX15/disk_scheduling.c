#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 50

void fcfs(int requests[], int n, int head)
{
    int seekTime = 0;
    printf("\nFCFS Disk Scheduling:\n");
    for (int i = 0; i < n; i++) {
        seekTime += abs(requests[i] - head);
        head = requests[i];
    }
    printf("Total seek time: %d\n", seekTime);
}

void scan(int requests[], int n, int head, int diskSize)
{
    int seekTime = 0;
    int left[MAX_REQUESTS], right[MAX_REQUESTS];
    int leftIndex = 0, rightIndex = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftIndex++] = requests[i];
        else
            right[rightIndex++] = requests[i];
    }

    // Sort left descending
    for (int i = 0; i < leftIndex - 1; i++)
        for (int j = i + 1; j < leftIndex; j++)
            if (left[i] < left[j]) { int t = left[i]; left[i] = left[j]; left[j] = t; }

    // Sort right ascending
    for (int i = 0; i < rightIndex - 1; i++)
        for (int j = i + 1; j < rightIndex; j++)
            if (right[i] > right[j]) { int t = right[i]; right[i] = right[j]; right[j] = t; }

    // Service right first, then left
    int cur = head;
    for (int i = 0; i < rightIndex; i++) {
        seekTime += abs(right[i] - cur);
        cur = right[i];
    }
    for (int i = 0; i < leftIndex; i++) {
        seekTime += abs(left[i] - cur);
        cur = left[i];
    }

    printf("\nSCAN Disk Scheduling:\n");
    printf("Total seek time: %d\n", seekTime);
}

void cscan(int requests[], int n, int head, int diskSize)
{
    int seekTime = 0;
    int left[MAX_REQUESTS], right[MAX_REQUESTS];
    int leftIndex = 0, rightIndex = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftIndex++] = requests[i];
        else
            right[rightIndex++] = requests[i];
    }

    // Sort right ascending
    for (int i = 0; i < rightIndex - 1; i++)
        for (int j = i + 1; j < rightIndex; j++)
            if (right[i] > right[j]) { int t = right[i]; right[i] = right[j]; right[j] = t; }

    // Sort left ascending
    for (int i = 0; i < leftIndex - 1; i++)
        for (int j = i + 1; j < leftIndex; j++)
            if (left[i] > left[j]) { int t = left[i]; left[i] = left[j]; left[j] = t; }

    int cur = head;
    // Move right to disk end
    for (int i = 0; i < rightIndex; i++) {
        seekTime += abs(right[i] - cur);
        cur = right[i];
    }
    // Jump to start, service left
    seekTime += abs(cur - (diskSize - 1));
    seekTime += (diskSize - 1);
    cur = 0;
    for (int i = 0; i < leftIndex; i++) {
        seekTime += abs(left[i] - cur);
        cur = left[i];
    }

    printf("\nC-SCAN Disk Scheduling:\n");
    printf("Total seek time: %d\n", seekTime);
}

void look(int requests[], int n, int head)
{
    int seekTime = 0;
    int left[MAX_REQUESTS], right[MAX_REQUESTS];
    int leftIndex = 0, rightIndex = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftIndex++] = requests[i];
        else
            right[rightIndex++] = requests[i];
    }

    // Sort left descending
    for (int i = 0; i < leftIndex - 1; i++)
        for (int j = i + 1; j < leftIndex; j++)
            if (left[i] < left[j]) { int t = left[i]; left[i] = left[j]; left[j] = t; }

    // Sort right ascending
    for (int i = 0; i < rightIndex - 1; i++)
        for (int j = i + 1; j < rightIndex; j++)
            if (right[i] > right[j]) { int t = right[i]; right[i] = right[j]; right[j] = t; }

    int cur = head;
    for (int i = 0; i < rightIndex; i++) {
        seekTime += abs(right[i] - cur);
        cur = right[i];
    }
    for (int i = 0; i < leftIndex; i++) {
        seekTime += abs(left[i] - cur);
        cur = left[i];
    }

    printf("\nLOOK Disk Scheduling:\n");
    printf("Total seek time: %d\n", seekTime);
}

void clook(int requests[], int n, int head)
{
    int seekTime = 0;
    int left[MAX_REQUESTS], right[MAX_REQUESTS];
    int leftIndex = 0, rightIndex = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftIndex++] = requests[i];
        else
            right[rightIndex++] = requests[i];
    }

    // Sort right ascending
    for (int i = 0; i < rightIndex - 1; i++)
        for (int j = i + 1; j < rightIndex; j++)
            if (right[i] > right[j]) { int t = right[i]; right[i] = right[j]; right[j] = t; }

    // Sort left ascending
    for (int i = 0; i < leftIndex - 1; i++)
        for (int j = i + 1; j < leftIndex; j++)
            if (left[i] > left[j]) { int t = left[i]; left[i] = left[j]; left[j] = t; }

    int cur = head;
    for (int i = 0; i < rightIndex; i++) {
        seekTime += abs(right[i] - cur);
        cur = right[i];
    }
    // Jump to smallest left request
    if (leftIndex > 0) {
        seekTime += abs(cur - left[0]);
        cur = left[0];
        for (int i = 1; i < leftIndex; i++) {
            seekTime += abs(left[i] - cur);
            cur = left[i];
        }
    }

    printf("\nC-LOOK Disk Scheduling:\n");
    printf("Total seek time: %d\n", seekTime);
}

int main()
{
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50;
    int diskSize = 200;

    fcfs(requests, n, head);
    scan(requests, n, head, diskSize);
    cscan(requests, n, head, diskSize);
    look(requests, n, head);
    clook(requests, n, head);

    return 0;
}
