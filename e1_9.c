#include <stdio.h>

#define IN 1
#define OUT 0
main()
{
    int state;
    state = OUT;
    char c;
    while((c = getchar())!=EOF)
    {
      if(c == ' ')
        if (state == OUT)
        {
          putchar(c);
          state = IN;
        }
        else
        {
        }
      else
      {
              putchar(c);
              state = OUT;
      }

    }

}
