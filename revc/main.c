#include <stdio.h>
#include <string.h>  

void revstr(char *str1);

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s <name>\n", argv[0]);
    return 1;
  }

  for(int i = argc - 1; i > 0; i--)
  {
    if (argv[i] != NULL) 
    {
      revstr(argv[i]);
      printf("%s ", argv[i]);
    }
  }

  printf("\n");
  return 0;
}


void revstr(char *str1)  
{
  int i, len, temp;
  len = strlen(str1);

  for (i = 0; i < len/2; i++)
  {
    temp = str1[i];
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
  }
}