#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

#define MEMSIZE     4

main()
{
    int shmid, shmid2;
    key_t key, key2;
	int* sharedInt1;
	int* sharedInt2;
   

    key = 5678;
	key2 = 6000;

 
	
	shmid = shmget(key, MEMSIZE, 0666); 
	
	shmid2 = shmget(key2, MEMSIZE, 0666);
	
	

  
	sharedInt1 = (int*) shmat(shmid, NULL, 0);
	sharedInt2 = (int*) shmat(shmid2, NULL, 0);
	
	*sharedInt1 = *sharedInt1 * *sharedInt1;
	while(*sharedInt2 > -10)
	{
		*sharedInt2 -= 1; 
		sleep(1);
	}
		
	
   

    
}