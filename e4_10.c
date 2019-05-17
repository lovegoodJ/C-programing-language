#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 1000

void push(double f);
double pop(void);
int getop(char s[],char line[]);

int mygetline(char line[], int maxline);


 int pos;
main()
{

  int type;
  double op2;
  char s[MAXOP];

  char line[MAXLINE];
  while(mygetline(line,MAXLINE)>0)
  {
    pos =0;
    while( (type = getop(s,line)) != '\n')
    {
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
        case '%':
          op2 = pop();
          if (op2 != 0.0)
            push((int) pop() % (int) op2);
          else
            printf("error mod zero\n");
          break;
        default:
          printf("Error, unknown commands.\n");
          break;
      }



  }
      printf(" %.8g\n", pop());
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
      // printf("sp %d\n", sp);
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

// void clear(void)
// {
//   sp = 0;
// }

#include<ctype.h>







int getop(char s[], char line[])
{
  int i, c;
  while((s[0] = c = line[pos++])== ' ' || c == '\t' )
  ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.' && c != '-')
    return c;

    i = 0;
  if( c == '-')
    if( !isdigit(s[++i] = c = line[pos++]))
      return '-';
    else{
      while(isdigit(s[++i] = c = line[pos++]))
      ;
    }

  if (isdigit(c))
    while(isdigit(s[++i] = c = line[pos++]))
    ;
 if(c == '.')
  while(isdigit(s[++i] = c = line[pos++]))
  ;
  s[i] = '\0';
  if(c != EOF)
    pos--;
  return NUMBER;
}

int mygetline(char line[], int lim)
{
  int c, i;
  for(i= 0; i<lim && (c=getchar()) != EOF && c != '\n'; i++)
    line[i] = c;
  if(c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}
