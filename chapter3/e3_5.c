#include<stdio.h>
#include<string.h>

void reverse(char s[]);

void itob(int n, char s[], int b);

main()
{
  int n = -((unsigned int)~0 >>1) -1 ;
  // int n = 15;
  int b = 8;
  char s[100];
  itob(n,s,b);
  printf("%d\n",n);
  printf("%s\n",s);
}


void itob(int n, char s[], int b)
{
  int i=0, sign;
  char c;
  unsigned int ui;
  if((sign=n)<0){
    ui = -n;
  }
  else{
    ui = n;
  }

  do{
    c = ui%b;
    if(c<10)
      s[i] = c + '0';
    else
      s[i] = c - 10 + 'A';
    i++;
  }while((ui= ui/b)>0);

  if(sign<0)
  {
    s[i]='-';
    i++;
  }
  s[i]='\0';
  reverse(s);

}

void reverse(char s[])
{
  int i, j;
  char c;
  for (i=0,j=strlen(s)-1; i<j;i++,j--)
  {
    c = s[i];
    s[i]= s[j];
    s[j]=c;
  }
}
