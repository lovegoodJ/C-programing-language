#include<stdio.h>

#define MAXLINE 1000
#define NEWLINE 10

int main()
{
    char longline[MAXLINE];

    char c;
    int pos = 0;
    while( (c = getchar()) != EOF )
    {
      if(c == ' '||c == '\t')
      {
        if(pos >NEWLINE)
        {
          putchar('\n');
          pos = 0;
        }
        else
        {
          putchar(c);
          pos++;
        }
      }
      else{
        putchar(c);
        pos++;
      }
    }


}
