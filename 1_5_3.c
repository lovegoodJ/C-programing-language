#include<stdio.h>

#define IN 1
#define OUT 0

main()
{

	int c;
	
        int state = IN;
	while ((c = getchar()) != EOF)
		if (c == '\t' || c == ' ')
			if (state = IN)
			{ 
				putchar(' ');
				state = OUT;
			}
		else
		{
			putchar(c);
			state = IN;
		}
}


