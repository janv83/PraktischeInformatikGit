#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int global = 42;



int main()
{
	int local = 42;
	global = rand();
	//int *zeiger = malloc(4);
	printf("%p\n", &local);
	printf("%p\n", &global);
	printf("%px\n", main);
	
	unsigned char* p = (unsigned char*)main;
	
	for(int i = 0; i < 10 ; i++)
	{
		printf("%02x ", p[i]);
	}
	
	//printf("%p\n", zeiger); //(heAP
	
/*	while(1)
	{
		printf("%d\n", global);
		sleep(1);
	}*/
	
	return 0;
}