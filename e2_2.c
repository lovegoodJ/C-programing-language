#include<stdio.h>

main()
{
  int lim = 100;
  char s[lim];

  int i = 0;
  char c;
  while( i < lim -1)
  {
    c = getchar();
    if(c == EOF)
    ;
    else if( c== '\n')
    ;
    else
    {
      putchar(c);
      i++;
    }
  }
  printf("%s",s);
}
