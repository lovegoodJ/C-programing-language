#include<stdio.h>
#include<string.h>

void reverse(char s[]);

void itoa(int n, char s[]);

main()
{
  int n = -((unsigned int)~0 >>1) -1 ;
  char s[100];
  itoa(n,s);
  printf("%d\n",n);
  printf("%s\n",s);
}

int i =0;
void itoa(int n, char s[])
{
  int  sign;
  unsigned int ui;
  if((sign=n)<0){
    ui = -n;
    s[i++] = '-';
  }
  else{
    ui = n;
  }
  if(ui/10)
    itoa(ui/10,s);
  s[i++] = ui%10 + '0';

  s[i]='\0';

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
