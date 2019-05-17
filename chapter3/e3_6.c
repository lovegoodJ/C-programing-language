#include<stdio.h>
#include<string.h>

void reverse(char s[]);

void itoa(int n, char s[], int w);

main()
{
  // int n = -((unsigned int)~0 >>1) -1 ;
  int n = -15;
  char s[100];
  int w = 8;
  itoa(n,s,8);
  printf("%d\n",n);
  printf("%s\n",s);
}


void itoa(int n, char s[], int w)
{
  int i=0, sign;
  unsigned int ui;
  if((sign=n)<0){
    ui = -n;
  }
  else{
    ui = n;
  }

  do{
    s[i] = ui%10 + '0';
    i++;
  }while((ui= ui/10)>0);

  if(sign<0)
  {
    s[i]='-';
    i++;
  }

  for (;i<w;i++)
  {
    s[i] = ' ';
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
