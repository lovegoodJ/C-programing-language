#include<stdio.h>

#define NTAB 8

int main()
{
  char c;

  int pos = 0;
  int nblank =0;

  while( (c = getchar()) != EOF)
  {
    if(c == '\t')
    {
      nblank = NTAB - (pos%NTAB);
      // printf("%d",nblank);
      for(int i =0; i<nblank; i++)
      {
        putchar('#');
        pos++;
      }
    }
    else
    {
      putchar(c);
      pos++;
    }
  }
}
