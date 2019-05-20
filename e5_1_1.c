#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int c);

int getint( int *pn);

main()
{
  int x;
  int *pn = &x;
  getint(pn);

  printf("%d\n", x);
}


int getint(int  *pn)
{
  int sign,c;

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
  *pn = *pn * sign;
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
