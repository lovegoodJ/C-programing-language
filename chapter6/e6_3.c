#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct line{
  int linenum;
  struct line *next;
};


struct tnode {
  char * word;
  struct line *l;
  struct tnode *left;
  struct tnode *right;
};

char * common[] ={
  "and",
  "is",
  "the"
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *root, char *word, int linenum);
struct line *addline(struct line *l, int linenum);

void treeprint(struct tnode *root);

int getword(char *word, int lim);


int main()
{
  struct tnode *root = NULL;
  char word[MAXWORD];
  int linenum = 1;

  while( getword(word, MAXWORD) !=EOF){
    if(word[0]=='\n')
    {
       printf("linenum %d\n", linenum);
            linenum++;
    }

    if (isalpha(word[0]))
    {
      if(root == NULL)
      {
      root = addtree(root, word,linenum);
      }else{
        addtree(root, word,linenum);
      }
       // treeprint(root);
    }
  }

  treeprint(root);
}

struct tnode *addtree(struct tnode *root, char *word, int linenum){
   struct tnode *p = root;
   int n;

   struct tnode *talloc(void);
   char *mystrdup(char *s);

   if (p== NULL)
   {
    p = talloc();
    p->word = mystrdup(word);
    p->l = addline(p->l, linenum);
    p->left = NULL;
    p->right = NULL;
    return p;
  } else if ( (n = strcmp(p->word, word))==0){
    addline(p->l,linenum);
    return p;
  } else if(n<0)
  {
    if(p->right == NULL)
    {
      p->right = addtree(p->right, word, linenum);
      return p->right;
    }

    else
      addtree(p->right, word,linenum);

  } else{
    if(p->left == NULL)
    {
      p->left = addtree(p->left, word, linenum);
      return p->left;
    }

    else
      addtree(p->left,word, linenum);
  }

}

struct line* addline(struct line * l, int linenum)
{
  struct line * p = l;
  struct line *lalloc(void);

  if(p ==NULL)
  {
    p = lalloc();
    p->next = NULL;
    p->linenum = linenum;
    return p;
  }
  while(1){
    if(p->linenum == linenum)
      return p;
    else{
      if(p->next != NULL)
        p = p->next;
      else{
        p->next = lalloc();
        p = p->next;
        p->next = NULL;
        p->linenum = linenum;
        return p;
      }
    }
  }


}

void treeprint(struct tnode *p){



  if(p != NULL)
  {
    struct line *l = p->l;
    treeprint(p->left);
    printf(" %s", p->word);
    while(l!=NULL){
      printf(" %d", l->linenum);
      l = l->next;
    }
    printf(" \n");
    treeprint(p->right);
  }


}


#include <stdlib.h>

struct tnode *talloc(void){
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct line * lalloc(void){
  return (struct line *) malloc(sizeof(struct line));
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

  while( isspace(c = getch()) && c !='\n')
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
