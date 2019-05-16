#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
  unsigned  num = 055;
  unsigned y = 077;

  int p=4;
  int n = 3;
  unsigned gb;
  gb = setbits(num, p, n,y);
  printf("%04o\n",gb);

}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned mask = ~0;
  unsigned y_most = y & ~(~0 << n);
  unsigned x_rmost = x & ~(~0 << (p-n));
  unsigned x_mask;
  x_mask =( ( ((x >> p) << n) | y_most ) << (p-n) )|x_rmost;
  return x_mask;
}
