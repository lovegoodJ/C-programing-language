#include <stdarg.h>

void minprintf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++){
     if (*p != '%'){
       putchar(*p);
       continue;
     }

     switch(*++p){
       case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", ival);
        break;
      case 's':
        sval = va_arg(ap, char *);
        printf("%s", sval);
        break;
      default:
        putchar(*p);
        break;
     }
  }
  va_end(ap);
}


int main()
{

  minprintf("hello %d would %s \n", 135, "haha");
  return 0;

 }
