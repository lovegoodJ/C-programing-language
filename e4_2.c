#include<stdio.h>

double atof(char str[]);

main()
{
  double num;

  char str[] = "-124.76";

  num = atof(str);

  printf("\t%g\n",num);

}


double atof(char str[])
{
  int i;
  int sign;
  double val =0;
  double power =1;
  for(i =0; str[i] ==' '; i++)
  ;
  sign = (str[i]=='-' ) ? -1: 1;

  if(str[i]=='-' || str[i]=='+')
    i++;

  for(;isdigit(str[i]);i++)
  {
    val = val*10 + str[i]-'0';
  }
  if(str[i] == '.')
  {
    i++;
  }
  for(;isdigit(str[i]);i++)
  {
    val = val*10 + str[i] - '0';
    power *= 10;
  }

  return sign*val/power;


}
