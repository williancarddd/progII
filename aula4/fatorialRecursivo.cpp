#include <stdlib.h>
#include <stdio.h>

long int fatorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n * fatorial(n - 1);
}
main()
{
  long int i = fatorial(5);
  printf("fatorial %d", i);
}