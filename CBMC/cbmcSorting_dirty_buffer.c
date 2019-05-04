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
	printf("Sorting is OK! \n"); 
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
		assert(isInside(copy, original[i], len));
	}
    
	printf("Permutation is OK!\n"); 
}
			
void isBufferOverrun(int insertingIndex, int arrayLen)
{
	assert(insertingIndex < arrayLen);
}
	

int main()
{
	int i, j, a, n, number[10];
	int sizeOfNumber = 10;
	printf("Enter the value of N \n");
	scanf("%d", &n);
    
	if (n <= 0)
		return 0;
	// malloc both array - orig and copy 
	//int* number = malloc(n * sizeof(int));	
	int* orig_number = malloc(n*sizeof(int));
	
	printf("Enter the numbers \n");
	for (i = 0; i < n; ++i)				
    {
        scanf("%d", &number[i]);
    }
		
	// save the original input array
	for (i = 0; i< n; i++)
	{
		isBufferOverrun(i, sizeOfNumber);
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
