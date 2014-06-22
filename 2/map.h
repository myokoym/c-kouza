#ifndef MAP_H
#define MAP_H

typedef struct _map map_t;

extern char * map_title;

map_t * map_new(int, int, int);
int map_free(map_t *);
int map_set_data(map_t *, int, int, unsigned char);
unsigned char map_get_data(map_t *, int, int);
int map_load_data(map_t *);
int map_save_data(map_t *);

#endif /* MAP_H */
