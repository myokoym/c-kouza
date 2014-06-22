#include "map.h"
#include <stdio.h>

int
main(void)
{
  map_t *map;
  int x_size = 20;
  int y_size = 20;
  unsigned char flag;

  printf("%s\n", map_title);

  map = map_new(x_size, y_size, 2);
  map_load_data(map);

  /* do editing, showing and etc. */
  flag = map_get_data(map, 10, 10);
  map_set_data(map, 15, 15, flag);

  map_save_data(map);
  map_free(map);

  return 0;
}
