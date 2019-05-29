#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int *ival;
  float *dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++){
     if (*p == ' '){
       continue;
     }

     switch(*++p){
       case 'd':
        ival = va_arg(ap, int *);
        scanf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, float *);
        scanf("%f", dval);
        break;
      case 's':
        sval = va_arg(ap, char *);
        scanf("%s", sval);
        break;
      case ' ':
        break;
      default:
        printf("Unmatch \n");
        break;
     }
  }
  va_end(ap);
}


int main()
{

  float sum, v;
  char s[100];
  sum = 0;

  // minscanf("%f", &v);
  // printf("Int %f\n", v);

  minscanf("%s", s);
  printf("S %s\n", s);
  return 0;

 }
