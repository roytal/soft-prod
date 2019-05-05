#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<klee/klee.h>


void isSorted( int * arr, int len)
{	
	for(int i = 0; i<len-1; i++)
	{
		if (arr[i+1] <arr[i])
		{
			printf("There is a problem with sorting!"); 
			klee_assert(0);
		}
	}
	printf("Sorting is OK!"); 
}

int isInside(int *arr, int x, int len)
{
	for (int i = 0 ; i<len ;i++)
	{
		if (arr[i] == x)
		{
			return 1;
		}
	}
	return 0;
}



void isPermotation(int * original, int * copy , int len)
{
	int i, copy_len;
	copy_len = sizeof(copy)/sizeof(int);
	if (copy_len != len )
	{
		printf("There is a problem with permutation - new array has differeny lenght"); 
		klee_assert(0);
	}
	
	for (i =0; i<len; i++)
	{
		if (!isInside(copy, original[i], len))
		{
			printf("There is a problem with permutation - new array has differeny values"); 
			klee_assert(0);
		}
	}
	printf("Permutation is OK!"); 
}
			
	
	
	

int main()
{
	int i, j, a, n = 3; 
		
	int number[3];	
	int* orig_number = malloc(n*sizeof(int));
	}
	klee_make_symbolic(number,n*sizeof(int),"number");

	
	// save the original input array
	for (i = 0; i< n-1; i++)
	{
		orig_number[i] = number[i];
	}

	// bubble sort algo
	for (i = 0; i < n-2; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (number[i] > number[j])
			{
				a =  number[i]; 
				number[i] = number[j];
				number[j] = a;
			}
		}
	}


	/*  Assertions
	assert that the array at the end is sorted
	for (i = 0; i < n -1; i++)
	{
	assert(number[i] < number[i+1]);
	}
	

	//checking if the array is not sorted
	//force klee to find if there is an input that canot be sorted by our procedure
	if (!isSorted(number,n))
	{
	  printf("the array is not sorted\n");
	  //klee_assert(0);
	}
	// assert that the array at the end is a permutation of the original array
	if (!isPermotation(orig_number, number, n))
	{
	  printf("some numbers are missing\n");
	  //klee_assert(0);

	}
	*/
	

	
	// Klee Assertions 
	isPermotation(orig_number, number, n);
	isSorted(number,n);		
	
	return 0;
}
