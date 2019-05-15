#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
  char c;
  int state = OUT;
  while((c = getchar()) != EOF)
  {
   if(c == ' '|| c == '\n'|| c== '\t')
   {
    if(state == IN)
    {
      putchar('\n');
      state = OUT;
    }
  }
   else
   {
     putchar(c);
     state = IN;
   }
  }
}
