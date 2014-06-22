#ifndef NUM_H
#define NUM_H

typedef struct _num {
  short val;
} num_t;

void   num_set_short(num_t *, short);
char * num_get_binary_string(num_t *);
void   num_scan_binary_string(num_t *, int, char *);

#endif /* NUM_H */
