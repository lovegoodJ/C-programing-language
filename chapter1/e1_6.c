#include<stdio.h>

main()
{

	int c;
	printf("%c",EOF);
	while (c =( getchar() != EOF)){
		printf("%d",c);
	}
}
