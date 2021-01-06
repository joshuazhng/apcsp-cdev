#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char c = 't';
  printf("char c value: %c and size: %lu bytes\n", c, sizeof(c));

  float f = 1.568;
  printf("float f value: %f and size: %lu bytes\n", f, sizeof(f));

  double d = 1.49257273;
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));

  unsigned int b = 200;
  printf("unsigned int b value: %d and size: %lu bytes\n", b, sizeof(b));

  short int p = 1250;
  printf("short int p value: %d and size: %lu bytes\n", p, sizeof(p));
}



