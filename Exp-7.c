#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH "file.txt"

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    // Create a unique key for the semaphore set
    key_t key = ftok(".", 'S');

    // Create or get the semaphore set
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semid == -1) {
        // Semaphore set already exists, get its ID
        semid = semget(key, 1, 0);
    } else {
        // Initialize the semaphore to unlocked state
        union semun arg;
        arg.val = 1;
        semctl(semid, 0, SETVAL, arg);
    }

    // Open the file
    int fd = open(FILE_PATH, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    struct sembuf sem_op;
    sem_op.sem_num = 0;     // Semaphore index in the set
    sem_op.sem_flg = 0;     // No special flags

    // Try to lock the semaphore
    sem_op.sem_op = -1;     // Decrement semaphore value
    printf("Attempting to lock the file...\n");
    semop(semid, &sem_op, 1);

    // Critical section: Access the file
    printf("File locked\n");
    printf("Performing some operations on the file...\n");
    sleep(3);  // Simulating some work on the file

    // Unlock the semaphore
    sem_op.sem_op = 1;      // Increment semaphore value
    semop(semid, &sem_op, 1);
    printf("File unlocked\n");

    // Close the file
    close(fd);

    // Remove the semaphore set
    semctl(semid, 0, IPC_RMID);

    return 0;
}
