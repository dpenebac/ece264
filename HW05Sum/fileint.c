// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  //
  FILE *file;
  int num;
  *sum = 0;  
  
  file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error when opening file");
    return(false);
  }
  
  //if fopen succeeds, read integers using fscan (do not use fgetc)
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  while(feof(file) == 0)
  {
    fscanf(file,"%d\n",&num);
    *sum += num;
  }

  fclose(file);

  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //

  FILE *file;  
  file = fopen(filename, "w");
  
  if (file == NULL)
  {
    printf("Error when opening file");
    return(false);
  }  
  
  fprintf(file,"%d\n",sum);
  fclose(file);

  return true;
}
#endif
