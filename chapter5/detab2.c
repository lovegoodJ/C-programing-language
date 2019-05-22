#include<stdio.h>

#define NTAB 8

int main(int argc, char *argv[])
{
  char c;

int numtabs = 0;
int m = 0;
char *s;

while(--argc>0)
{
  int i =0;
  s = *++argv;
  if(s[0] == '+')
    for(i=1;s[i]!='\0';i++)
      numtabs =numtabs*10 + s[i] -'0';

      if(s[0] == '-')
        for(i=1;s[i]!='\0';i++)
          m =m*10 + s[i] -'0';
}

if(numtabs ==0)
  numtabs = NTAB;

  int pos = 0;
  int nblank =0;

  while( (c = getchar()) != EOF)
  {
    if(c == '\t')
    {
      if (pos>m)
      {
        nblank = numtabs - (pos%numtabs);
        // printf("%d",nblank);
        for(int i =0; i<nblank; i++)
        {
          putchar('#');
          pos++;
        }
      } else
      {
        putchar(c);
      }

    }
    else
    {
      putchar(c);
      pos++;
    }
  }
}
