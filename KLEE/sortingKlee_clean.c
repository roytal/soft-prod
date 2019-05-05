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
			//printf("There is a problem with sorting!\n"); 
			//klee_assert(0);
		}
	}
	printf("Sorting is OK!\n"); 
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
	for (i =0; i<len; i++)
	{
		if (!isInside(copy, original[i], len))
		{
			printf("There is a problem with permutation\n"); 
			//klee_assert(0);
		}
	}
	printf("Permutation is OK!\n"); 
}
			
	
	
	

int main()
{
	int i, j, a;
	int n = 3;
	int number[n];
	
// 	printf("Enter the value of N \n");
	// using klee to set the value of n or take from user - lenght of array 
// 	scanf("%d", &n);
 	
	//klee_make_symbolic(&n,sizeof(n),"n");
	klee_make_symbolic(number, n*sizeof(int), "number");
	//assume n ia a little number for avoiding malloc errors
	//klee_assume(1<n  && n< 20);
	// malloc both array - orig and copy 
	//number = malloc(n * sizeof(int));	
	int* orig_number = malloc(n*sizeof(int));
	
	//printf("Enter the numbers \n");
	// take numbres from user or set with klee
// 	for (i = 0; i < n; ++i)
// 	{
// 		scanf("%d", &number[i]);
// 	}
	

	
	// save the original input array
	for (i = 0; i< n-2; i++)
	{
		orig_number[i] = number[i];
	}

	// bubble sort algo
	for (i = 0; i < n; ++i)
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
	
	// printing the new sorted array 
	/*printf("The numbers arranged in ascending order are given below \n");
	for (i = 0; i < n; ++i)
	{
		printf("here is %0x\n", number[i]);
	}
	*/
	// Klee Assertions 
	isPermotation(orig_number, number, n);
	isSorted(number,n);
	printf("END OF RUNNING\n");
	
	return 0;
}
