#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>

int main()
{
    int child, shmid, i;
    char *shmptr;

    child = fork();

    if (child != 0) {
        // PARENT PROCESS - writes to shared memory
        shmid  = shmget(2041, 32, 0666 | IPC_CREAT);
        shmptr = shmat(shmid, 0, 0);

        printf("\nPARENT PROCESS WRITING\n");
        for (i = 0; i < 10; i++) {
            shmptr[i] = 'a' + i;
            putchar(shmptr[i]);
        }
        printf("\n");

        wait(NULL); // Wait for child to finish
    }
    else {
        // CHILD PROCESS - reads from shared memory
        shmid  = shmget(2041, 32, 0666);
        shmptr = shmat(shmid, 0, 0);

        printf("\nCHILD PROCESS READING\n");
        for (i = 0; i < 10; i++)
            putchar(shmptr[i]);
        printf("\n");

        shmdt(shmptr);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
