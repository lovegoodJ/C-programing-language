#include<stdio.h>
#include<stdlib.h>
#include "calc.h"


#define MAXOP 100



main()
{

  int type;
  double op2;
  char s[MAXOP];

  while( (type = getop(s)) != EOF)
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
