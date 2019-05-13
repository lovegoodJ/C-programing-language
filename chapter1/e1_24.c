#include<stdio.h>



main()
{

  int np=0;
  char c;j
  while((c= getchar()) != EOF)
  {
    if(c=='{')
      np++;
    if(c=='}')
      np--;

  }

  if(np!=0)
    printf("Number of parentheses unequal:%d",np);
}
