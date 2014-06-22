#include "num.h"
#include <stdio.h>
#include <stdlib.h>

void
num_set_short(num_t *num, short val)
{
  num->val = val;
}

char *
num_get_binary_string(num_t *num)
{
  int  size = 16;
  char *str = (char *)malloc((sizeof(char) * size) + 1);
  char buf[size];
  int  i;

  for (i = 0; i < size; i++) {
    sprintf(buf, "%d", (num->val >> i) & 0x01);
    str[size - (i + 1)] = buf[0];
  }
  str[size] = '\0';

  return str;
}

void
num_scan_binary_string(num_t *num, int size, char *str)
{
  char buf[size];
  int  i;

  for (i = 0; i < size; i++) {
    sprintf(buf, "%d", (num->val >> i) & 0x01);
    str[size - (i + 1)] = buf[0];
  }
  str[size] = '\0';
}
