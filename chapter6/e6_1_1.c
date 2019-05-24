#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatite", 0,
    "while", 0
};

#define MAXWORD 100
int getword(char *, int);
int binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof keytab[0])

int main(){


  char word[MAXWORD];
  int n, i;

  while( getword(word, MAXWORD) != EOF)
  {

    // printf(" 11111\n");
    // printf("%s\n", word);
    if(isalpha(word[0]) || word[0] == '_')
      if( (n = binsearch(word, keytab, NKEYS))>=0 )
        keytab[n].count++;
  }


  for(i = 0; i<NKEYS; i++){
    if(keytab[i].count >0)
    {
      printf(" %d %s \n", keytab[i].count, keytab[i].word);
    }
  }

  return 0;
}

int binsearch(char * word, struct key * keytab, int nkeys)
{
  int i, j, mid;
  i = 0;
  j = nkeys -1;
  int cp;

  while(i<=j){
    mid = (i+j)/2;
    if ((cp = strcmp(word, keytab[mid].word)) >0)
    {
      i = mid + 1;
    } else if (cp <0) {
      j = mid -1;
    } else{
      return mid;
    }
  }

  return -1;
}


int getword(char * word, int lim)
{
  char * w = word;
  int c;

  int getch();
  void ungetch(int c);

  while( isspace(c = getch()))
    ;


  if(c != EOF){
    *(w++) = c;
  }

  if(!isalpha(c) && c != '_')
  {
    *w = '\0';
    return c;
  }



  for (; --lim >0; w++)
  {
    if(! isalnum( *w = getch()) && *w != '_')
    {
      ungetch(*w);
      break;
    }
  }

  *w = '\0';

  return w[0];
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
