#include<stdio.h>

#define NTAB 8

int main(int argc, char *argv[])
{
  char c;

int numtabs = 0;

while(--argc>0)
{
  int i =0;
  if((*++argv)[0] == '+')
    for(i=1;(*argv)[i]!='\0';i++)
      numtabs =numtabs*10 + (*argv)[i] -'0';
}

if(numtabs ==0)
  numtabs = NTAB;

  int pos = 0;
  int nblank =0;

  while( (c = getchar()) != EOF)
  {
    if(c == '\t')
    {
      nblank = numtabs - (pos%numtabs);
      // printf("%d",nblank);
      for(int i =0; i<nblank; i++)
      {
        putchar('#');
        pos++;
      }
      pos =0;
    }
    else
    {
      putchar(c);
      pos++;
    }
  }
}
