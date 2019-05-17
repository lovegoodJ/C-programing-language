#include<stdio.h>

int bitcount(unsigned x);

main()
{
  unsigned x = 055;

  int bits;
  bits = bitcount(x);
  printf("number of 1s : %d\n",bits);
}

int bitcount(unsigned x)
{
  int b =0;

  while(x  !=0){
      b++;
      x &= (x-1);
  }

  return b;
}
