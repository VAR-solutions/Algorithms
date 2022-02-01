#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	int x;
	int y;
} Point;

typedef struct Endp {
	int *result;
	int count;
} Endp;

void Destroy_endp(Endp *endp);

Point *Point_create(int x, int y);
void Point_destroy(Point *p);
void Print_point(Point *p, char *name);
void Copy_point(Point *a, Point *b);
void Destroy_list_points(Point **points, int nmemb);

void Swap_points(Point *a, Point *b);
int right_turn(Point *p, Point *q, Point *r);
void sort_by_coordinate(Point **lista, int p, int r, char coordinate);
void sort_clockwise(Point **points, int p, int r, int nmemb);
int partition(Point **lista, int p, int r, char coordinate);
Endp *endpoints(Point **points, int nmemb);

Point **get_upper(Point **points,  int nmemb);
Point **get_lower(Point **points, int nmemb);
Point **Convex_hull(Point **points, int nmemb);
