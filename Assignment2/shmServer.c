#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#define MEMSIZE  4 //integer

main()
{
   
    int shmid;
	int shmid2;
    key_t key;
	key_t key2;
  
	int* sharedInt1;
	int* sharedInt2;

    key = 5678;
	key2 = 6000;


	
	shmid = shmget(key, MEMSIZE,IPC_CREAT | 0666);
	
	shmid2 = shmget(key2, MEMSIZE, IPC_CREAT | 0666);


	sharedInt1 = (int*) shmat(shmid, NULL, 0);
	
	sharedInt2 = (int*) shmat(shmid2, NULL, 0);
	
	
 
    
	
	*sharedInt1 = 5;
	
	*sharedInt2 = 6;

 
    while (*sharedInt2 != -10)
	{
		sleep(1);
		std::cout << *sharedInt1 << std::endl;
	}
        
		
	

   
}