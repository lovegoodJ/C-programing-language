#include<stdio.h>
#include"calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if(sp >= MAXVAL)
    printf("stack error\n");
  else
    {
      val[sp++] = f;
    }
}


double pop(void)
{
  if(sp==0)
    printf("stack no item\n");
  else
    return val[--sp];
}


double top(void)
{
  if(sp==0)
    printf("stack no item\n");
  else
    return val[sp-1];
}

void swap(void)
{

  if(sp<2)
    printf("stack less then 2 item\n");
  else
  {
    double tmp;
    tmp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = tmp;
  }
}

void clear(void)
{
  sp = 0;
}
