#include<stdio.h>
#include<math.h>

double atof(char str[]);

main()
{
  double num;

  char str[] = "-124.76e-2";

  num = atof(str);

  printf("\t%g\n",num);

}


double atof(char str[])
{
  int i;
  int sign;
  double val =0;
  double power =1;
  int e=0;
  int esign;
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
  if(str[i]=='e')
    i++;

  esign = (str[i]=='-') ? -1 : 1;
  if ( str[i]== '-' || str[i] == '+')
  {
    i++;
  }
  for(; isdigit(str[i]); i++)
  {
    e = e*10 + str[i] - '0';
    printf("e: %d\n", e);
  }


  double sci = pow(10, esign*e);
  printf("sci: %d\n",sci);
  return sign*val/power*sci;


}
