#include <stdio.h>
#include <string.h>

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


int main(){

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
