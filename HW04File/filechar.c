// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{

  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  //

  FILE *file;
  unsigned char oneChar;

  file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error when opening file");
    return(false);
  }

  do 
	{
		oneChar = fgetc(file);
    
		if (feof(file) == 1)
		{
			break;
		}
		
		if (oneChar > 0 && oneChar < size - 1)
		{
      counts[oneChar] += 1;
		}	  

	} while(1);

  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //

  

  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  fclose(file);
  return(true);
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
  int ind;
  char oneChar;
  for (ind = 0; ind < size - 1; ind++)
  {
    if ((ind <= 'z' && ind >= 'a') || (ind >= 'A' && ind <= 'Z'))
    {
      oneChar = ind;
    }
    else
    {
      oneChar = ' ';
    }
    
    if (counts[ind] != 0)
    {
      printf("%d, %c, %d\n",ind,oneChar,counts[ind]);
    }  
  }
}
#endif
