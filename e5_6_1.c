#include<stdio.h>

double atof(char *str);

main()
{
  double num;

  char str[] = "-124.76";

  num = atof(str);

  printf("\t%g\n",num);

}


double atof(char *str)
{
  int i;
  int sign;
  double val =0;
  double power =1;
  for(; *str ==' '; str++)
  ;
  sign = (*str=='-' ) ? -1: 1;

  if(*str=='-' || *str=='+')
    str++;

  for(;isdigit(*str);str++)
  {
    val = val*10 + *str-'0';
  }
  if(*str == '.')
  {
    str++;
  }
  for(;isdigit(*str);str++)
  {
    val = val*10 + *str - '0';
    power *= 10;
  }

  return sign*val/power;


}
