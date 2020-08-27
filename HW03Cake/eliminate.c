// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements


  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif

/*
#include <stdio.h>

int main()
{
    int n = 6;
    int k = 3;
    int temp = k;
    int i = 0;
    int c;
    int currIndex = 0;
    
    int arr[n];
    
    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    
    for (i = 0; i < n - 1; i++)
    {
        k = temp;
        
        while (k > 0)
        {
            if (currIndex == n - 1)
            {
                currIndex = 0;
            }
            else
            {
                currIndex += 1;
            }
            
            if (arr[currIndex] != n)
            {
                k -= 1;
            }
        }
        
        printf("%d\n",arr[currIndex]);
        arr[currIndex] = n;
        
        for (c = 0; c < n; c++)
        {
            printf("%d ", arr[c]);
        }
        printf("\n");
    } 
    
    return (0);
}

*/
