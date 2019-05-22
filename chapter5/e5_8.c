#include <stdio.h>

static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};


int day_of_year(int year, int month, int day);

void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
  int year = 1988;
  int yearday = 60;

  int month = 2;
  int day = 29;

  int yd = day_of_year(year, month, day);

  int m, d;
  month_day(year, yearday, &m, &d);

  printf("yd %d\n", yd);
  printf(" m %d d %d \n", m, d);
}



int day_of_year(int year, int month, int day)
{
  int leap;
  leap = year%4 ==0 && year%100 !=0 || year%400 ==0;

  int m;
  for(m = 1; m<month; m++)
  {
    day += daytab[leap][m];
  }
  return day;

}


void month_day(int year, int yearday, int *m, int *d)
{
  int leap;
  leap = year%4 ==0 && year%100 !=0 || year%400 ==0;
  for(*m=1; yearday> daytab[leap][*m]; (*m)++ )
  {
    yearday -= daytab[leap][*m];
  }
  *d = yearday;
}
