#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

void isSorted( int * arr, int len)
{	
	for(int i = 0; i<len-1; i++)
	{
		assert(arr[i+1] >= arr[i]);		
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
// 	copy_len = sizeof(copy)/sizeof(int);
	
// 	assert(copy_len == len );
	printf("the old and new arrays are from the same lenght"); 
	
	for (i =0; i<len; i++)
	{
		assert(isInside(copy, original[i], len));
	}
    
	printf("Permutation is OK!"); 
}
			
	
	
	

int main()
{
	int i, j, a, n; //, number[30];
	
	printf("Enter the value of N \n");
	scanf("%d", &n);
    	
	if (n <= 0)
		return 0;
	// malloc both array - orig and copy 
	int* number = malloc(n * sizeof(int));	
	int* orig_number = malloc(n*sizeof(int));
	
	printf("Enter the numbers \n");
	for (i = 0; i < n; ++i)
		
    {
        scanf("%d", &number[i]);
    }
		
	// save the original input array
	for (i = 0; i< n; i++)
	{
		orig_number[i] = number[i];
	}

	// bubble sort algo
	for (i = 0; i < n; ++i)
	{
		// SORTING BUG!!!!!!!!!!!!!!!
		for (j = i + 1; j < n-1; ++j)
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
	printf("The numbers arranged in ascending order are given below \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d\n", number[i]);
	}
	
	// CMBC Assertions 
	isPermotation(orig_number, number, n);
	isSorted(number,n);		
	
	return 0;
}
