#include<stdio.h>

#define MAXLINE 1000

int getlinebook(char line[], int maxline);

void copy(char to[], char from[]);

main()
{

	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getlinebook(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return  0;
}


int getlinebook(char s[], int lim)
{
	int c, i, num;
	num = 0;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i){
		if ( c != ' ' && c != '\t'){
			s[num] = c;
			num = num + 1;
		}
	}
	if (c == '\n'){
		s[num] = c;
		++num;
	}

	s[num] = '\0';
	return num;
}


void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
