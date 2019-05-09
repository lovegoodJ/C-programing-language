#include<stdio.h>

#define MAXLINE 1000

int getlinebook(char line[], int maxline);

void copy(char to[], char from[]);

void reverse(char reverse[], char org[]);

main()
{

	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	char rev[MAXLINE];
	max = 0;
	while ((len = getlinebook(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0){
		reverse(rev, longest);	
		printf("%s", rev);
	}
	return  0;
}


int getlinebook(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}


void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}


void reverse(char reverse[], char org[])
{
	int len;
	len = 0;
	while(org[len] != '\n')
		++len;
	printf("%d\n", len);
	int i;
	for (i =0; i< len; ++i)
	{
	   reverse[i] = org[len -1 -i];
	}

	reverse[len] = '\0';
}
