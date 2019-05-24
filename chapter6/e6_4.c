#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct tnode {
  char * word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *root, char *word);

void treeprint(struct tnode *root);

int getword(char *word, int lim);

struct tnode  *treesort(struct tnode *sorted, struct tnode *root);
struct tnode *addsortedtree(struct tnode *root, struct tnode *nt);

int main()
{
  struct tnode *root = NULL;
  struct tnode *sorted = NULL;
  char word[MAXWORD];

  while( getword(word, MAXWORD) >0){

    if (isalpha(word[0]))
    {
      if(root == NULL)
      {
                root = addtree(root, word);
      }else{
        addtree(root, word);
      }

    }
  }

  treeprint(root);
  printf("1111111\n");
  sorted = treesort(sorted, root);
  printf("2222222\n");
  treeprint(sorted);
}

struct tnode  *treesort(struct tnode *sorted, struct tnode *root){
  struct tnode *p = root;



    if(p != NULL)
    {
      struct tnode *left = p->left;
      struct tnode *right = p->right;
      p->left = NULL;
      p->right = NULL;
      printf( "treesort %s\n", p->word);
      sorted = addsortedtree(sorted, p );
            printf( "treesort %s\n", p->word);
       treesort(sorted, left);

       treesort(sorted, right);
      return sorted;
    } else{
      return sorted;
    }
}

struct tnode *addsortedtree(struct tnode *root, struct tnode *tn){
   struct tnode *p = root;
   int n;



   if (p== NULL)
   {
     if (tn == NULL)
     {
       return NULL;
     } else{
       p = tn;

     }
  } else if ( tn == NULL){
    ;
  } else if( ( n = p->count - tn->count) >= 0)
  {

    if(p->left == NULL)
    {
      p->left = tn;
      p=tn;
    }else{
          printf("left\n");
      p = addsortedtree(p->left, tn);
    }

  } else{

    if(p->right == NULL)
    {
      p->right = tn;
      p= tn;
    }else {
      printf("right\n");
      p = addsortedtree(p->right, tn);
    }

  }
  printf("add %s\n",p->word);
    return p;
}


struct tnode *addtree(struct tnode *root, char *word){
   struct tnode *p = root;
   int n;

   struct tnode *talloc(void);
   char *mystrdup(char *s);

   if (p== NULL)
   {
    p = talloc();
    p->word = mystrdup(word);
    p->count = 1;
    p->left = NULL;
    p->right = NULL;
    return p;
  } else if ( (n = strcmp(p->word, word))==0){
    p->count++;
    return p;
  } else if(n<0)
  {
    if(p->right == NULL)
      p->right = addtree(p->right, word);
    else
      addtree(p->right, word);

  } else{
    if(p->left == NULL)
      p->left = addtree(p->left, word);
    else
      addtree(p->left,word);
  }

}

void treeprint(struct tnode *p){


  if(p != NULL)
  {
    treeprint(p->left);
    printf(" %d, %s\n", p->count, p->word);
    treeprint(p->right);
  }


}


#include <stdlib.h>

struct tnode *talloc(void){
  return (struct tnode *) malloc(sizeof(struct tnode));
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
