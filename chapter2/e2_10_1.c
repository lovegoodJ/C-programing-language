#include<stdio.h>

int lower(int c);

main()
{

  char c = 'C';

  printf("%c\n", lower(c));



}

int lower(int c)
{
  return (c >= 'A' && c<= 'Z') ? c - 'A'+'a' : c;
}
