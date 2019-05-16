#include<stdio.h>

int lower(int c);

main()
{

  char c = 'd';

  printf("%c\n", lower(c));



}

int lower(int c)
{
  if(c >= 'A' && c <='Z')
  {
    return c - 'A' + 'a';
  }
  else
  {
    return c;
  }
}
