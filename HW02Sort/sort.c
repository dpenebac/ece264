// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  int temp; //temp variable for swaping values
  int smallestIndex; //index of smallest value in array
  int findIndex; //index to search across array
  int placeIndex; //index to place the smallest value

  for (placeIndex = 0; placeIndex < size; placeIndex++) //for loop to place smallest indexes
  {
    smallestIndex = placeIndex; //set the smallest to be the first value in the "unsorted array"

    for (findIndex = placeIndex; findIndex < size; findIndex++) //search accross the unsorted array
    {
      if (arr[findIndex] < arr[smallestIndex]) //if the value at findIndex is smaller than the value at smallestIndex
      {
        smallestIndex = findIndex; //change smallestIndex to be the findIndex
      }
    }

    temp = arr[placeIndex]; //set temp variable to be the value at which we are placing the smallest variable
    arr[placeIndex] = arr[smallestIndex]; //set the smallest variable at the current place index
    arr[smallestIndex] = temp; //set teh original location of the smallest variable to the temp variable
  }

  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // This is the syntax to read or write an array element:
  // int x = arr[4];
  // read the value of arr[4] and store it in x
  // arr[4] = 5;
  // stores 5 in the element arr[4]
  // Please remember that indexes start from 0.

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
}
#endif
