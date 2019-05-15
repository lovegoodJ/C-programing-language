#include<stdio.h>

unsigned getbits(unsigned x, int p, int n);

main()
{
  unsigned  num = 055;

  int p=4;
  int n = 3;
  unsigned gb;
  gb = getbits(num, p, n);
  printf("%04o\n",gb);

}

unsigned getbits(unsigned x, int p, int n)
{
  return (x>>(p -n) & ~(~0 <<n));
}
