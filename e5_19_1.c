#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN  100

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
  int type;
  char temp[MAXTOKEN];


  while(gettoken() != EOF)
  {
    strcpy(out, token);
        // printf("%s\n", out);
    while(gettoken() != '\n'){
      if(tokentype == PARENS || tokentype == BRACKETS){
        strcat(out, token);
      }else if(tokentype == '*'){
        gettoken();
        if(tokentype == PARENS || tokentype == BRACKETS)
        {
          sprintf(temp, "*%s",out);
          strcpy(out,temp);
        }
        else{
          sprintf(temp,"(*%s)",out);
          strcpy(out,tmep);
        }
      }else if(tokentype == NAME){
        sprintf(temp, " %s %s", token, out);
        strcpy(out, temp);
      }else {
        printf("Error\n");
      }
              // printf("%s\n", out);
    }
    printf("%s\n", out);

    return 0;
  }


}




int gettoken(void)
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  // printf("1111111111111111\n");
  while((c= getch()) ==' ' || c == '\t' )
    ;

  if(c == '(')
  {
    c = getch();
    if(c == ')')
      {
        strcpy(token, "()");
        // printf("%s\n", token);
        return tokentype = PARENS;
      }
    else{
      ungetch(c);
      // printf("%s", token);
      return tokentype = '(';
    }
  } else if(c=='['){
      for(*p++ =c; (*p++ = getch())!= ']'; )
        ;
      *p ='\0';
      return tokentype = BRACKETS;
    } else if(isalpha(c)){
        for(*p++ =c; isalnum(c = getch());)
          *p++ = c;
        *p = '\0';

        ungetch(c);
        // printf("%s\n", token);
        return tokentype = NAME;
    }else
    {
      return tokentype = c;
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
