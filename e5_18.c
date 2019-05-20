#include <stdio.h>
#include <sting.h>
#include <ctype.h>

#define MAXTOKEN = 100

enum{NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main()
{
  while(gettoken != EOF)
  {
    strcpy(datatype, token);
    out[0]= '\0';
    dcl();
    if(tokentype != '\n')
      printf("Error 1 \n");
    else
      printf("%s[] %s %s\n", name, out, datatype);
  }


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
