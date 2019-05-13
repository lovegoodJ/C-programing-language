#include<stdio.h>

main()
{

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
  printf("fahr\t celsius\n");
  for(fahr = upper;fahr>lower;fahr = fahr -20)
  {
    celsius = (fahr - 32)*5.0/9.0;
    printf("%6.1f\t %6.1f\n",fahr, celsius);
  }
}
