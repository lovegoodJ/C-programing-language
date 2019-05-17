#include<stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
  unsigned  num = 055;

  int p=4;
  int n = 3;
  unsigned gb;
  gb = invert(num, p, n);
  printf("%04o\n",gb);

}

unsigned invert(unsigned x, int p, int n)
{
  unsigned mask = (~(~0 << n)) << (p-n);
  printf("%04o\n", mask);
  unsigned x_mask = (~x) & mask;
  printf("%04o\n", x_mask);
  return (x&(~mask) |x_mask);
}
