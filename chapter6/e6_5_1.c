#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s!='\0'; s++){
    hashval += *s + 31*hashval;
  }

  return hashval%HASHSIZE;
}


struct nlist *lookup(char *s)
{
  struct nlist * p = hashtab[hash(s)];

  for(; p!= NULL; p= p->next)
    if(p!=NULL)
      if( strcmp(p->name,s)==0)
        return p;

  return NULL;
}

char *mystrdup(char *);

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if((np = lookup(name))==NULL){
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = mystrdup(name))==NULL)
      return NULL;
    hashval= hash(name);

    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
      free((void*) np->defn);
  }

  if((np->defn = mystrdup(defn)) ==NULL)
    return NULL;

  return np;
}

void undef(char *s)
{
  struct nlist *np, *p, *prev;
  unsigned hashval = hash(s);
  np = lookup(s);
  if(np ==NULL){
    printf("not find\n");
  } else {
      p = hashtab[hashval];
      prev = p;
      if(p==np){
        hashtab[hashval] = p->next;
        free(p);
      } else{
        for(; p!= NULL; p= p->next)
          if(p ==np)
          {
            prev->next = p->next;
            free(p);
          } else{
            prev = p;
          }

      }


  }
}

#define WORDLEN 100
int main()
{

  char word[WORDLEN];
  char name[WORDLEN];
  char defn[WORDLEN];
  int c;
  struct nlist *np, *p;

  while( (getword(word, WORDLEN))!= EOF)
  {
    if(word[0]=='#')
      if(strcmp(word,"#define")==0){
        getword(name, WORDLEN);
        while( (c = getword(word,WORDLEN))!='\n' && c!= EOF)
        {
          strcat(defn, " ");
          strcat(defn, word);
        }
        np = install(name, defn);
        }

  }


  int i;
  for (i = 0; i<HASHSIZE; i++)
  {
    for(p = hashtab[i]; p!= NULL; p= p->next)
      if(p!=NULL)
        printf("%s  %s\n",p->name, p->defn);
  }

  getword(word,WORDLEN);

  undef(word);


  for (i = 0; i<HASHSIZE; i++)
  {
    for(p = hashtab[i]; p!= NULL; p= p->next)
      if(p!=NULL)
        printf("%s  %s\n",p->name, p->defn);
  }


}


char *mystrdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1);

  if(p!= NULL)
  {
    strcpy(p, s);
  }

  return p;
}



int getword(char * word, int lim)
{
  char * w = word;
  int c;

  int getch();
  void ungetch(int c);

  while( isspace(c = getch())&& c!='\n')
    ;


  if(c != EOF){
    *(w++) = c;
  }

  if(!isalnum(c) && c != '_' && c!='#')
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

  return word[0];
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
