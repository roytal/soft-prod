#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <klee/klee.h>

int isSorted( int * arr, int len)
{	
	for(int i = 0; i++; i< len-1)
	{
		if (arr[i+1] <arr[i])
		{
				return 0;
		}
	}
	return 1;
			
}

int isInside(int *arr, int x, int len)
{
	for (int i = ; i++; i < len)
	{
		if (arr[i] == x)
		{
			return 1;
		}
	}
	return 0;
}



int isPermotation(int * original, int * copy , int len)
{
		int i, copy_len;
		copy_len = copy/ sizeof(int);
		if (copy_len != len )
		{
			return 0;
		}
		
		for (i =0; i<len; i++)
		{
			if (!isInside(copy, original[i], len))
			{
				return 0;
			}
		}return 1;
}
			
	
	
	

void main()
{

  int i, j, a, n; //, number[30];
  printf("Enter the value of N \n");
  scanf("%d", &n);

  int* number = malloc(n * sizeof(int));
  //for prmotation checking
  int* copy = malloc(n*sizeof*int));
  

  printf("Enter the numbers \n");
  //let klee find the "bad input"
  klee_make_symbolic(number, n, "number");
  //for (i = 0; i < n; ++i)
    //scanf("%d", &number[i]);
  // save the original imput array
  for (i = 0; i< n; i++){
	  copy[i] = number[i];
  }
	  
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


  /* assert that the array at the end is sorted
  for (i = 0; i < n -1; i++)
    {
      assert(number[i] < number[i+1]);
    }
  */
  
  //checking if the array is not sorted
  //force klee to find if there is an input that canot be sorted by our procedure
  if (!isSorted(number,n))
  {
	  printf("the array is not sorted\n");
	  klee_assert(0)
  }
  // assert that the array at the end is a permutation of the original array
  if (!isPermotation(original, copy, n))
  {
	  printf("some numbers are missing\n");
	  klee_assert(0);
	  
  }
  //TODO the right way!!!

  printf("The numbers arranged in ascending order are given below \n");
  for (i = 0; i < n; ++i)
  {
    printf("%d\n", number[i]);
  }


}
