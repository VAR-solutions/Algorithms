/*
 * This file contains an implementation of convex hull problem
 * Pseudocode: Slow algorithm
 * Input: A set of points in the plane.
 * Output: A list L containing the vertices of CH(P) (conex hull of P)
 * in clockwise order.
 * 	Steps:
 * 	1. E <-- {} Create an empty set.
 * 	2. for all ordered pairs (p, q) in PxP with p not equal to q:
 * 	3. 	do valid <-- true
 * 	4. 	for all points r in P not equal to p or q
 * 	5.		do if r lies to the left of the directed line from p to q
 * 	6.			then valid <-- false
 * 	7.	if valid then Add the directed edge pq to E
 * 	8. From the set E of edges construct a list L of vertices of CH(P), sorted
 * 	clockwise order.
 * This method is very bad and not robust. A much better aproach would be the next one.
 * Pseudoce: Fast algorithm.
 * Input: Set of points in a plane
 * Output: A list containing the points in CH(P) in clockwise order.
 * 1. Sort the points by x coordinates, resulting in a sequence p1,...,pn.
 * 2. Put points p1 and p2 in a list L_upper with p1 as the first point.
 * 3. for i <-- 3 to n
 * 4. 	do append pi to L_upper
 * 5.		while L_upper contains more than two points and the last three points do not make a right turn.
 * 6. 			do Delete the middle of the last three points in L_upper
 * 7. Put p1 and pn in the list L_lower, with pn as the first point.
 * 8. for i<-- n-2 downto 1
 * 9. 	do append pi to L_lower
 * 10. 		while L_lower contains more than 2 points and the last 3 points
 * 		in L_lower do not make a right turn.
 * 11. 			do delete the middle of the last three points  from L_lower.
 * 12. Remove the first and the last point from L_lower to avoid dupplication of the points
 * 	where the upper and the lower hull meet.
 * 13. Append L_lower to L_upper and call the resulting list L.
 * 14. return L
 * Notes:
 * 1. If two points have the same x coordinate we should ordere them by the y coordinate.
 * 2. If the three points lie on the same line we will assume that they make a left turn.
 * 3. Points that are very close need to be rounded.
 *
 * Theorem:The convex hull of a set of n points in the plane can be computed in O(nlog(n)) time.
 * */
#include <assert.h>
#include <string.h>
#include "convex.h"

void Destroy_endp(Endp *endp)
{
	free(endp->result);
	free(endp);
}

void Swap_points(Point *a, Point *b)
{
	Point *tmp = Point_create(a->x, a->y);
	if (!tmp)
		printf("Not enough memory\n");

	a->x = b->x;
	a->y = b->y;

	b->x = tmp->x;
	b->y = tmp->y;
	free(tmp);
}

/*right_turn: return 1 if the r point is at the right of the segment pq,
 * anf 0 otherwise. Here r is the point in the middle.*/
int right_turn(Point *p, Point *r, Point *q)
{
	double det = (q->x*r->y - q->y*r->x) - (p->x*r->y-p->y*r->x) + (p->x*q->y-p->y*q->x);
	int result = det <= 0 ? 0 : 1;
	return result;
}

/*sort_by_coordinate: The given list of points by the specified coordinate.*/
void sort_by_coordinate(Point **lista, int p, int r, char coordinate)
{
	int q = 0;
	if (p < r) {
		q = partition(lista, p, r, coordinate);
		sort_by_coordinate(lista, p, q-1, coordinate);
		sort_by_coordinate(lista, q+1, r, coordinate);
	}
}

/*cmp: compare function, used to sort the sequences by x or y coordinates.*/
int cmp(Point *a, Point *b, char coordinate)
{
	if (coordinate == 'x')
		return a->x <= b->x;
	return a->y <= b->y;
}

/*partition: partitions the list. Needed for sort_by_coordinate*/
int partition(Point **lista, int p, int r, char coordinate)
{
	Point *pivot = lista[r];
	int i = p-1;
	int j = 0;

	for (j = p; j < r; j++) {
		if(cmp(lista[j], pivot, coordinate)) {
			i++;
			Swap_points(lista[i], lista[j]);
		}
	}

		Swap_points(lista[i+1], lista[r]);
	return i+1;
}

/*endpoints: is meant to be used after the sorting of x-coordinates.
 * Store pairs of endpoints that represents the subarray with equals
 * x coordinates.*/
Endp *endpoints(Point **points, int nmemb)
{
	Endp *endp = calloc(nmemb, sizeof(Endp));
	if (!endp)
		return NULL;

	int *result = calloc(nmemb, sizeof(int));
	if (!result)
		return NULL;
	
	int i = 1, j = 0, k = 0;
	for ( i = 1; i < nmemb; i++) {
		if (points[i]->x != points[j]->x) {
			if (j != (i-1)) {
				result[k] = j, result[k+1] = i-1;
				k += 2;
			}
			j = i;
		}
	}

	endp->result = result;
	endp->count = k;
	return endp;
}

/*sort_clockwise: do first a sort by x coordinate and then by y coordinate.*/
void sort_clockwise(Point **points, int p, int r, int nmemb)
{
	sort_by_coordinate(points, p, r, 'x');
	Endp *endp = endpoints(points, nmemb);
	int i = 0;
	for ( i = 0; i < endp->count; i = i + 2) 
		sort_by_coordinate(points, endp->result[i], endp->result[i+1], 'y');
	Destroy_endp(endp);
}


Point *Point_create(int x, int y)
{
	Point *p = malloc(sizeof(struct Point));
	if (!p)
		return NULL;
	p->x = x;
	p->y = y;
	return p;
}

void Point_destroy(Point *p)
{
	assert(p != NULL);
	free(p);
}

void Print_point(Point *p, char *name)
{
	printf("%s=[%d, %d]\n", name, p->x, p->y);
}

void Copy_point(Point *a, Point *b)
{
	a->x = b->x;
	a->y = b->y;
}

void Destroy_list_points(Point **points, int nmemb)
{
	int i = 0;
	for (i = 0; i < nmemb; i++) 
		Point_destroy(points[i]);
	free(points);
}

/*get_upper: get the upper bound of the convex hull.*/
Point **get_upper(Point **points, int nmemb)
{
	Point **L_upper = calloc(nmemb, sizeof(struct Point*));
	if (!L_upper) {
		printf("Out of memory\n");
		return NULL;
	}
	
	L_upper[0] = points[0]; L_upper[1] = points[1];
	int ulast_index = 1;

	int i = 0;
	for (i = 2; i < nmemb; i++) {
		if (ulast_index >= nmemb-1) {
			printf("Index out of bound: L_upper\n");
			goto error;
		}

		L_upper[ulast_index+1] = points[i];
		ulast_index++;
		while (ulast_index >= 2 && !right_turn(L_upper[ulast_index-2], L_upper[ulast_index-1], L_upper[ulast_index])) {
			/*delete the middle of the last three point*/
			L_upper[ulast_index-1] = L_upper[ulast_index];
			L_upper[ulast_index] = NULL;
			if (L_upper[ulast_index-1] == NULL) {
				printf("Uff bad stuff! Deleting middle point in L_upper.\n");
				goto error;
			}
			ulast_index--;
		}
	}
	
	return L_upper;
error:
	free(L_upper);
	return NULL;
}

/*get_lower: return the lower bound of the convex hull.*/
Point **get_lower(Point **points, int nmemb)
{
	Point **L_lower = calloc(nmemb, sizeof(struct Point*));
	if (!L_lower) {
		printf("Out of memory\n");
		return NULL;
	}

	L_lower[0] = points[nmemb-1]; L_lower[1] = points[nmemb-2];
	int llast_index = 1;

	int i = 0;
	for (i = nmemb-3; i >= 0; i--) {
		if (llast_index >= nmemb-1) {
			printf("Index out of bound: L_lower\n");
			goto error;
		}

		L_lower[llast_index+1] = points[i];
		llast_index++;
		while (llast_index >= 2 && !right_turn(L_lower[llast_index-2], L_lower[llast_index-1], L_lower[llast_index])) {
			L_lower[llast_index-1] = L_lower[llast_index];
			L_lower[llast_index] = NULL;
			if (L_lower[llast_index-1] == NULL) {
				printf("Uff bad stuff! Deleting middle point in L_lower.\n");
				goto error;
			}
			llast_index--;
		}
	}
	
	return L_lower;
error:
	free(L_lower);
	return NULL;
}

/*Convex_hull: we pass the list of points and the
 * number of elements in that list.*/
Point **Convex_hull(Point **points, int nmemb)
{
	if (nmemb < 3) {
		printf("Sorry must be more than three points\n");
		return NULL;
	}
	
	/*sort the entire array of points.*/
	sort_clockwise(points, 0, nmemb-1, nmemb);	
	
	Point **L_upper = get_upper(points, nmemb);
	if (!L_upper)
		return NULL;
	
	Point **L_lower = get_lower(points, nmemb);
	if (!L_lower) {
		free(L_upper); //this is ok.
		return NULL;
	}

	Point **uptr = L_upper;
	int ulast_index = -1;
	while (*uptr != NULL) {
		ulast_index++;
		uptr++;
	}

	Point **lptr = L_lower;
	int llast_index = -1;
	while (*lptr != NULL) {
		llast_index++;
		lptr++;
	}	
	
	/*Remove the first and the last point in L_lower to avoid dupplication of points.*/
	L_lower[llast_index] = NULL; /*remove the last one.*/
	llast_index--;
	Point **ptr = L_lower;
        ptr++;	/*just put the pointer one step forward.*/

	while (*ptr != NULL) {
		if (ulast_index >= nmemb) {
			printf("STOP!!! BAD STUFFS HERE\n");
			goto error;
		}
		L_upper[ulast_index+1] = *ptr;
		ptr++;
		ulast_index++;
	}
	
	free(L_lower);
	//Destroy_list_points(L_lower, llast_index);
	return L_upper;

error:
	/*this way of freeing is a bad idea.*/
	free(L_lower);
	free(L_upper);
	return NULL;
}

/*Here we start some basics tests.*/
void test_swap(Point *a, Point *b)
{
	/*Swap_position*/
	printf("Checking swap_points\n");
	printf("a=[%d, %d] and b=[%d, %d]\n", a->x, a->y, b->x, b->y);
	Swap_points(a, b);
	printf("a=[%d, %d] and b=[%d, %d]\n", a->x, a->y, b->x, b->y);
}

void test_endpoints(Point **points, int nmemb)
{
	printf("\nTesting endpoints\n");
	Endp *endp = endpoints(points, nmemb);
	int i = 0;
	for (i = 0; i < endp->count; i++) 
		printf("%d ", endp->result[i]);
	Destroy_endp(endp);
}

void test_sort_by_coordinate(Point **lista, int nmemb, char coordinate)
{
	/*sort_clockwise*/
	printf("\nChecking sort_by_coordinate %c\n", coordinate);
	printf("Before sort_by_coordinate %c\n", coordinate);
	int i = 0;
	for (i = 0; i < nmemb; i++)
		printf("[%d, %d] ", lista[i]->x, lista[i]->y);
	printf("\n");

	sort_by_coordinate(lista, 0, nmemb-1, coordinate);
	printf("After sort_clockwise\n");
	for (i = 0; i < nmemb; i++)
		printf("[%d, %d] ", lista[i]->x, lista[i]->y);
	printf("\n");
}


void test_sort_clockwise(Point **lista, int nmemb)
{
	/*sort_clockwise*/
	printf("\nChecking sort_clockwise\n");
	printf("Before sort_clockwise\n");
	int i = 0;
	for (i = 0; i < nmemb; i++)
		printf("[%d, %d] ", lista[i]->x, lista[i]->y);
	printf("\n");

	sort_clockwise(lista, 0, nmemb-1, nmemb);
	printf("After sort_clockwise\n");
	for (i = 0; i < nmemb; i++)
		printf("[%d, %d] ", lista[i]->x, lista[i]->y);
	printf("\n");
}

void test_convex_hull(Point **lista, int nmemb)
{
	printf("\nTesting convex hull\n");
	Point **result = Convex_hull(lista, nmemb);
	
	Point **ptr = result;
	int size = 0;
	while (*ptr != NULL) {
		size++;
		ptr++;
	}
	printf("The convex hull has %d elements\n", size);
	
	int i = 0;
	for (i = 0; i < size; i++) 
		printf(" \033[0;34m-->\033[0m \033[0;32m[%d, %d]\033[0m", result[i]->x, result[i]->y);
	printf("\n");

	Destroy_list_points(lista, nmemb);
	free(result);
}

int testit_all(void)
{
	/*Necesaries declarations*/
	Point *a = Point_create(1, 2), *b = Point_create(2, 3);
	Point *c = Point_create(4, 5), *d = Point_create(-1, 2);
	Point *e = Point_create(6, 2), *f = Point_create(1, 3);
	Point *g = Point_create(0, 0);
	if (!a)
		return 1;
	if (!b)
		return 1;
	if (!c)
		return 1;
	if (!d)
		return 1;
	if (!e)
		return 1;
	if (!f)
		return 1;
	if (!g)
		return 1;

	Point **lista = malloc(sizeof(struct Point*)*7);
	if (!lista)
		return 1;
	
	lista[0] = a; lista[1] = b; lista[2] = c; lista[3] = d;
	lista[4] = e; lista[5] = f; lista[6] = g;

	test_swap(a, b);

	/*right_turn*/
	printf("\nChecking right_turn\n");
	if (right_turn(d, f, a))
		printf("d, f, a makes a right turn\n");
	else
		printf("d, f, a makes a left turn\n");

	if (right_turn(d, a, f))
		printf("d, a, f makes a right turn\n");
	else
		printf("d, a, f makes a left turn\n");
	
	/*sort_by_partition*/
	test_sort_by_coordinate(lista, 7, 'x');
	
	/*endpoints*/
	test_endpoints(lista, 7);

	/*sort_clockwise*/
	test_sort_clockwise(lista, 7);

	/*convex_hull*/
	test_convex_hull(lista, 7);

	return 0;
}

int main(int argc, char *argv[])
{
	if(testit_all())
		return 1;
	return 0;
}
