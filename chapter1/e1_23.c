#include<stdio.h>

#define IN 1
#define OUT 0

main()
{

  char c1,c2;
  int state = OUT;

  while((c1= getchar()) != EOF)
  {
    if(state == OUT){
      if(c1 =='/')
      {
        if(( c2 = getchar())!= EOF||c2 =='*')
        {
          state = IN;
        }
        else{
          putchar(c1);
          putchar(c2);
        }
      }
      else{
        putchar(c1);
      }
    }
    else{
      if(c1 == '*')
      {
        if(( c2 = getchar())!= EOF||c2 =='/')
        {
          state = OUT;
        }

      }



    }
  }


}
