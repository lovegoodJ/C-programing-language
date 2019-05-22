#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int c);

int getfloat( float *pn);

main()
{
  float x;
  float *pn = &x;
  getfloat(pn);

  printf("%f\n", x);
}


int getfloat(float  *pn)
{
  int sign, c, pow=1;

  while( isspace(c = getch()))
    ;

  if(!isdigit(c) && c != '+' && c != '-' && c != EOF)
  {
    ungetch(c);
    return 0;
  }


  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();

  if(!isdigit(c))
  {
    ungetch(c);
    return 0;
  }

  for(*pn = 0; isdigit(c);c = getch())
  {
    *pn = *pn*10 + c - '0';
  }

  if(c == '.')
    c = getch();

  for(; isdigit(c);c = getch())
  {
    *pn = *pn*10 + c - '0';
    pow *=10;
  }



  *pn = *pn * sign/pow;

  if(c != EOF)
  {
    ungetch(c);
  }

  return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp >0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(bufp >= BUFSIZE)
    printf("buf error\n");
  else
  {
    buf[bufp++] = c;
  }
}
