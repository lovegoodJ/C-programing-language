#include <stdio.h>

main()
{
    int nb, nt, nn;
    nb = 0;
    nt = 0;
    nn =0;
    char c;
    while((c = getchar())!=EOF)
    {
      if(c == ' ')
        nb++;
      if( c == '\t')
        nt++;
      if( c == '\n')
        nn++;
    }
    printf("nb:%d nt:%d nn:%d\n", nb, nt, nn);
}
