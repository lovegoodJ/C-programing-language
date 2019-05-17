#include<stdio.h>

 void escape(char s[], char t[]);

main()
{
  char s[50];
  char t[] ="\the\tllo\nhello";
  printf("%s \n",t);

  escape(s, t);
  printf("%s \n",s);
}


void escape(char s[], char  t[])
{
  int i;
  int j =0;
  char c;
  for(i =0; t[i]!='\0'; i++)
  {
    c = t[i];
    switch(c)
    {
      case '\t':
        s[j] = '\\';
        j++;
        s[j] = 't';
        j++;
        break;
      case '\n':
        s[j] = '\\';
        j++;
        s[j]= 'n';
        j++;
        break;
      default:
        s[j] = c;
        j++;
        break;
    }
  }
  s[j]='\0';

}
