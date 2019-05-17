#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#define MAXOP 100
#define NUMBER '0'
#define FUNC 'f'

void push(double f);
double pop(void);
int getop(char s[]);

void mathfunc(char s[]);


main()
{

  int type;
  double op2;
  char s[MAXOP];

  while( (type = getop(s)) != EOF)
  {
    printf("%c\t %s \n",type,s);
    switch (type){

      case FUNC:
        mathfunc(s);
        break;
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
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int) pop() % (int) op2);
        else
          printf("error mod zero\n");
        break;
      case '\n':
        printf(" %.8g\n", pop());
        break;
      default:
        printf("Error, unknown commands.\n");
        break;
    }
  }
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


void mathfunc(char s[])
{
  if(strcmp(s,"sin") == 0)
  {
    push(sin(pop()));
  }
  else if(strcmp(s,"exp") == 0)
    push(exp(pop()));
  else if(strcmp(s, "pow") == 0)
  {
    double op2;
    op2 = pop();
    push(pow(pop(),op2));
  }
  else
    printf("Error, unknown function.\n");

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

  if(islower(c))
  {
    i = 0;
    while(islower(s[++i] = c = getch()))
    ;
    s[++i] = '\0';
    return FUNC;
  }
  if(!isdigit(c) && c != '.' && c != '-')
    return c;

    i = 0;
  if( c == '-')
    if( !isdigit(s[++i] = c = getch()))
      return '-';
    else{
      while(isdigit(s[++i] = c = getch()))
      ;
    }

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
