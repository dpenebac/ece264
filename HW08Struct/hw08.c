// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", )
  FILE *file;
  file = fopen(filename,"rb");
  if (file == NULL)
  {
    return(false);
  }
  
  int seek = fseek(file,0L,SEEK_END);
  long len = ftell(file);
  len = len / sizeof(Vector);

  fclose(file);
  return(len);
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  // 
  FILE *file = fopen(filename, "rb");
  int numIntegers;
  if (file == NULL)
  {
    return(false);
  }

  numIntegers = fread(& vecArr[0], sizeof(Vector), size, file);
  if (numIntegers != size)
  {
    return(false);
  }
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  fclose(file);
  return(true);
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  
  const Vector *ptr1 = (const Vector *) p1;
  const Vector *ptr2 = (const Vector *) p2;
  int val1 = ptr1 -> x;
  int val2 = ptr2 -> x;
  if (val1 < val2)
  {
    return(-1);
  }
  else if (val1 > val2)
  {
    return(1);
  }

  val1 = ptr1 -> y;
  val2 = ptr2 -> y;
  if (val1 < val2)
  {
    return(-1);
  }
  else if (val1 > val2)
  {
    return(1);
  } 

  val1 = ptr1 -> z;
  val2 = ptr2 -> z;
  if (val1 < val2)
  {
    return(-1);
  }
  else if (val1 > val2)
  {
    return(1);
  } 

  return(0);
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  FILE *file = fopen(filename, "wb");
  if (file == NULL)
  {
    return(false);
  }
  // if fopen fails, return false
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  // 
  // fclose and return true
  fwrite(&vecArr[0],sizeof(Vector),size,file);
  return(true);
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
