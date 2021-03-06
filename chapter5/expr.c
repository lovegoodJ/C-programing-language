#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXOP 100
#define NUMBER '0'
#define SIN 's'
#define EXP 'e'
#define POW 'p'

void push(double f);
double pop(void);
int getop(char s[]);


int main(int argc, char *argv[])
{

  int type;
  double op2;
  char s[100];

  while( --argc >0)
  {

    strcpy(s, *++argv);
    printf(" argc %d %s\n", argc, s);
    if(!isdigit( s[0]) && s[1] =='\0')
        type = s[0];
    else if(isdigit(s[0]) || isdigit(s[1]))
       type = NUMBER;
    else
    {
      type = -1;
    }
    printf("%c\t %s \n",type,s);
    switch (type){
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() /op2);
        else
          printf("error div zero\n");
        break;

      default:
        printf("Error, unknown commands.\n");
        break;
    }
  }

    printf(" %.8g\n", pop());

return 0;
}

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

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c;
  while((s[0] = c = getch())== ' ' || c == '\t' )
  ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c;

  i = 0;
  if (isdigit(c))
    while(isdigit(s[++i] = c = getch()))
    ;
 if(c == '.')
  while(isdigit(s[++i] = c = getch()))
  ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
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
