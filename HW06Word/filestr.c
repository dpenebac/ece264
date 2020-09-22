// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char word[], char * line, int size)
{
  // filename: name of the input file
  // word: the word to search
  // line: temporary space to store what is read from the file
  // size: size of line

  // open a file whose name is filename for reading
  // if fopen fails, return -1. 
  // if fopen succeeds, set sum to zero
  // use fgets to read the file
  // if word appears in a line, add one to sum
  
  FILE *file;
  file = fopen(filename,"r");
  int wordCount = 0;
  int i = 0;
  int c = 0;
  char space = ' ';

  if (file == NULL)
  {
    printf("Error in file opening");
    return(-1);
  }

  while (fgets(line,size,file) != NULL)
  {
//printf("%s\n",line);
    for (i = 0; i < size - 1; i++)
    {
      c = 0;
      while(true)
      {
        if (line[i + c] != word[c] || line[i] == space)
        {
          break;
        }
        else if (c == strlen(word) - 1)
        {
          wordCount++;
          i = i + c;
          line[i] = word[c] + 1;
        }
        c++;
      }
    }
  }

  return(wordCount);

  // It is possible that the same word appears multiple times in a line
  // If this word is split in two or more lines, do not count the word.
  
  // It is also possible that a long line is split by fgets. If this happens,
  // do not count the word.

  // return sum
 
  // If a line is "aaaaa" and the word is "aa", how is the count defined?
  // In this assignment, the first two letters are consumed when the

  // the first match occurs. Thus, the next match starts at the third
  // character. For this case, the correct answer is 2, not 4.
}
#endif















