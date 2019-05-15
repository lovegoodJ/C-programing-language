#include <stdio.h>

float ftoc(float fah);

main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahr\tCelsius\n");
  while (fahr <= upper) {
    celsius = ftoc(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}


float ftoc(float fah)
{
  float cel = (5.0/9.0)*(fah-32.0);
  return cel;
}
