// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  FILE *file;
  file = fopen(filename,"r");
  int numNums = 0;
  int temp;

  if (file == NULL)
  {
    printf("Error in file opening");
    return(-1);
  }

  while(fscanf(file,"%d",&temp) == 1)
  {
    numNums++;
  }

  fclose(file);
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
  return(numNums);
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.

  FILE *file;
  file = fopen(filename,"r");
  int numNums = 0;
  int temp;
  int i = 0;

  if (file == NULL)
  {
    printf("Error in file opening");
    return(-1);
  }

  while(fscanf(file,"%d",&temp) == 1)
  {
    numNums++;
    intArr[i] = temp;
    i++;
  }

  if (numNums != size)
  {
    return(false);
  }
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  fclose(file);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  return( *(int*)p1 - *(int*)p2);
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  FILE *file;
  file = fopen(filename,"w");
  int i;

  if (file == NULL)
  {
    printf("Error in file opening");
    return(false);
  }

  for (i = 0; i < size; i++)
  {
    fprintf(file,"%d\n",intArr[i]);
  }
  // fclose and return true

  fclose(file);
  return(true);
}
#endif
