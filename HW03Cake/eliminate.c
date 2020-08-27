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

  int i; //loop variable
  int c; //loop variable
  int currIndex = n - 1; //current index that is being selected
  int marked = n + 1; //variable to show that the index has been selected previously
                                                                                                                                                                                                
  for (i = 0; i < n; i++) //loop from 0 to n
  {
     arr[i] = i + 1; //set each value in the array to be the current index + 1
  }

  for (i = 0; i < n; i++) //loop from 0 to n
  {
    
    for (c = 0; c < k; c++) //loop from 0 to k
    {
      if (currIndex == n - 1) //if the current Index is n-1 (end of array)
      {
        currIndex = 0; //send current index back to beginning
      }
      else //if not at end of array
      {
        currIndex += 1; //increment current index by 1
      }
       
      if (arr[currIndex] == marked) //if the current index is marked
      {
        c--; //reduce c by 1 effectivily skipping this loop
      }
    }
        
    printf("%d\n",currIndex); //output the current index
    arr[currIndex] = marked; //mark the arr where the current index is
  }
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
