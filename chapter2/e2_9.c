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

  for(int i = 0; x !=0; x =(x>>1))
  {
    if(x & 01 == 1)
    {
      b++;
    }
  }
  return b;
}
