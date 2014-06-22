#ifndef MAP_PRIVATE_H
#define MAP_PRIVATE_H

#include "map.h"

struct _map {
  unsigned char **ptr; /* map[y][x] */
  int x_size;
  int y_size;
  unsigned char bitl; /* a bit length of a point */
  unsigned char bitf; /* a mask value for bitl */
};

#endif /* MAP_PRIVATE_H */
