#ifndef GRID_H
#define GRID_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <render.h>
#include <cdt.h>

typedef struct _grid Grid;

typedef struct _node_list {
    Agnode_t*          node;
    struct _node_list* next;
} node_list;

typedef struct {
    int          i, j;
} gridpt;

typedef struct {
    gridpt       p;        /* index of cell */
    node_list*   nodes;    /* nodes in cell */
    Dtlink_t     link;     /* cdt data */
} cell;

extern Grid*      mkGrid (int);
extern void       adjustGrid (Grid* g, int nnodes);
extern void       clearGrid (Grid*);
extern void       addGrid (Grid*, int, int, Agnode_t*);
extern void       walkGrid (Grid*, int(*)(Dt_t*,cell*,Grid*));
extern cell*      findGrid (Grid*, int, int);
extern void       delGrid (Grid*);
extern int        gLength (cell* p);

#endif
