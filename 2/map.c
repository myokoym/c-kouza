#include "map-private.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * map_title = "The Map";

map_t *
map_new(int x_size, int y_size, int bitl)
{
  int i, y;
  map_t *map;

  map = (map_t *) malloc(1 * sizeof(map_t));

  map->bitl = bitl;
  while (8 % map->bitl != 0) {
    map->bitl++;
  }

  map->bitf = 0;
  for (i = 0; i < bitl; i++) {
    map->bitf += (1 << i);
  }

  map->x_size = ((x_size * map->bitl) >> 3);
  if (x_size * map->bitl - map->x_size * 8 != 0) {
    map->x_size++;
  }
  map->x_size++;
  map->y_size = y_size + 1;
  
  map->ptr = (unsigned char **) malloc(map->y_size * sizeof(unsigned char *));
  for (y = 0; y < map->y_size; y++) {
    map->ptr[y] = (unsigned char *) malloc(map->x_size * sizeof(unsigned char));
    memset(map->ptr[y], 0, map->x_size * sizeof(unsigned char));
  }

  return map;
}

int
map_free(map_t *map)
{
  int y;

  for (y = 0; y < map->y_size; y++) {
    free(map->ptr[y]);
  }
  free(map->ptr);

  return 0;
}

int
map_set_data(map_t *map, int x, int y, unsigned char flag)
{
  int xp, xoffset;

  xp = (x * map->bitl) >> 3;
  xoffset = x * map->bitl - xp * 8;
  
  map->ptr[y][xp] = (((unsigned char) flag << xoffset) & (map->bitf << xoffset))
                      + (map->ptr[y][xp] &~ (map->bitf << xoffset));

  return 0;
}

unsigned char
map_get_data(map_t *map, int x, int y)
{
  int xp, xoffset;

  xp = (x * map->bitl) >> 3;
  xoffset = x * map->bitl - xp * 8;
  
  return ((map->ptr[y][xp] >> xoffset) & map->bitf);
}

int
map_load_data(map_t *map)
{
  int x, y;

  for (y = 0; y < map->y_size; y++) {
    for (x = 0; x < map->x_size; x++) {
      map_set_data(map, x, y, '1'); //fgetc(stdin);
      if (feof(stdin)) {
        return -1;
      }
    }
  }

  return 0;
}

int
map_save_data(map_t *map)
{
  int x, y;

  for (y = 0; y < map->y_size; y++) {
    for (x = 0; x < map->x_size; x++) {
      fputc(map_get_data(map, x, y), stdout);
    }
  }

  return 0;
}
