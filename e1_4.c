#include <stdio.h>

main()
{
  float celsius, fahr;

  printf("Celsius\t Fahrenheit\n");
  int lower, upper, step;
  lower =-100;
  upper = 200;
  step = 20;
  celsius = lower;
  while(celsius < upper)
  {
    fahr = celsius *9.0/5.0 + 32;
    printf("%f\t %f\n",celsius,fahr );
    celsius = celsius + step;
  }
}
