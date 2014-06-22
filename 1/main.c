#include "num.h"
#include <stdio.h>
#include <stdlib.h>

short get_short_from_stdin();
void  display_short_binary(num_t *);

int
main(void)
{
  num_t num;

  while (1) {
    num_set_short(&num, get_short_from_stdin());
    display_short_binary(&num);
  }

  return 0;
}

short
get_short_from_stdin()
{
  char  buf[80];
  short num;
  int   n;

  printf("Input = ");
  fgets(buf, sizeof(buf), stdin);
  n = sscanf(buf, "%hd", &num);
  if (n != 1) {
    num = 0;
  }

  return num;
}

void
display_short_binary(num_t *num)
{
  /*
  int size = 16;
  char str[size + 1];
  num_scan_binary_string(num, size, str);
  printf("%s\n", str);
  */
  char *str;
  str = num_get_binary_string(num);
  printf("%s\n", str);
  free(str);
}
