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

int error =0;
int prevtoken = 0;



int main()
{
  while(gettoken() != EOF)
  {
    // printf("dcl %s\n", token);
    strcpy(datatype, token);
    out[0]= '\0';
    dcl();
    if(tokentype != '\n')
      printf("Error 1 \n");
    else
      printf("%s: %s %s\n", name, out, datatype);
  }


}


void dcl(void)
{


  int ns;

  for(ns = 0; gettoken() == '*';)
    ns++;

  printf("dcl\n");
  dirdcl();

  while(ns-- >0)
    strcat(out, " pointer to");
}

void dirdcl(void)
{
  int type;
 printf("tokentype %d, token %s\n", tokentype, token);
  if (tokentype == '('){
    dcl();
    if (tokentype != ')')
      tokenerror("Error massing )\n");
  }else if( tokentype == NAME){
    strcpy(name, token);
    printf("111111\n");
  }else{
    tokenerror("Error, expect name or (dcl)\n");

  }

  while( (type = gettoken()) == PARENS || type == BRACKETS)
  {
    if(type == PARENS)
      strcat(out, " function returning");
    else{
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }

  if(error ==1)
  {
    error =0;
    prevtoken =1;
    dcl();
  }

}


// ##########################################################



void tokenerror(char *s)
{
  printf("%s",s);
  error =1;
}

int gettoken(void)
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  if(prevtoken ==1)
  {
    prevtoken =0;
    return tokentype;
  }

  // printf("1111111111111111\n");
  while((c= getch()) ==' ' || c == '\t' )
    ;

  if(c == '(')
  {
    c = getch();
    if(c == ')')
      {
        strcpy(token, "()");
        printf("%s\n", token);
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
        printf("%s\n", token);
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
