#include<stdio.h>

unsigned rightrot(unsigned x,  int n);


main()
{
  unsigned  num = 055;

  int n = 3;
  unsigned gb;
  gb = rightrot(num, n);
  printf("%o\n",gb);

}

unsigned rightrot(unsigned x,  int n)
{
  int len;

  len = bits();
  printf("%d\n",len);
  unsigned mask = (~(~0 << n));
    printf("%o\n",mask);

  unsigned x_mask = (x & mask) << (len -n);

  return ( (x>>n) |x_mask);
}

int bits(void)
{
  unsigned x = ~0;

  int i;
  for (i = 1; (x = x>>1) >0; i++)
      // printf("%d\n",i);
  ;
  return i;
}
