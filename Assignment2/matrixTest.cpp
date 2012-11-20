#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <iostream>

#define SM (64 / sizeof(double))


int main()
{
	
	int N = 1000;
	
	
	double* mul1 = new double[N*N];
	double* mul2 = new double[N*N];
	double* res = new double[N*N];
	
	double* tmp = new double[N*N];
	
	

	
	
	
	//initialisation of the matrices
	for (int i = 0; i <N; ++i)
	{
		for (int j = 0; j< N; ++j)
		{
			//std::cout << "I: " << i  << std::endl;
			//	std::cout <<" J : " << j  << std::endl;
			
				res[i*N+j]= 0.0;
				mul1[i*N+j]= 1.0;
				mul2[i*N+j]= 2.0;
				
				
			
		}
	}
	
	
	


  clock_t begin = clock();

  

	for (int i = 0; i <N; ++i)
	{
		for (int j = 0; j< N; ++j)
		{
			for (int k = 0;k < N; ++k)
			{
				res[i*N+j]+= mul1[i*N+k] * mul2[k*N+j];
			}
		}
	}



	

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	
	
	
	
	 begin = clock();

	for (int i = 0; i <N; ++i)
	{
		for (int j = 0; j< N; ++j)
		{
			//std::cout << "I: " << i  << std::endl;
			//	std::cout <<" J : " << j  << std::endl;
			
				tmp[i*N+j] = mul2[j*N+i];
				
				
			
		}
	}
  

	for (int i = 0; i <N; ++i)
	{
		for (int j = 0; j< N; ++j)
		{
			for (int k = 0;k < N; ++k)
			{
				res[i*N+j]+= mul1[i*N+k] * tmp[j*N+k];
			}
		}
	}



	

  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	
	
	 begin = clock();
	
	double* rres;
	double* rmul1;
	int i2;
	int k2;
	int j2;
	double* rmul2;
	
	for(int i = 0; i < N; i+=SM)
	{
		for(int j = 0; j < N; j+= SM)
		{
			for(int k = 0; k < N; k+= SM)
			{
				for(i2= 0, rres = &(res[i*N+j]), rmul1 = &mul1[i*N+k]; i2 < SM; ++i2, rres += N, rmul1 += N)
				{
					for(k2= 0, rmul2 = &(mul2[k*N+j]); k2 < SM; ++k2, rmul2 += N)
					{
						for(j2 = 0; j2< SM; ++j2)
						{
							rres[j2] +=  rmul1[k2] * rmul2[j2];
						}
					}
				}
			}
		}
	}
	
	 end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	
	delete [] res;
	delete [] mul1;
	delete [] mul2;
	delete [] tmp;
	
}