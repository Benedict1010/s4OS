#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSZ 27

int main()
{
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	key = 5678;

	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}
	if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
	{
		perror("shmat");
		exit(1);
	}
	printf("Write something to shared memory:\n");
	fgets(shm, SHMSZ, stdin);
	printf("Data written to shared memory.\nRun the reader program to read it.\n");
	if (shmdt(shm) == -1)
	{
		perror("shmdt");
		exit(1);
	}
	return 0;
}
