#ifndef _minitest_h
#define _minitest_h
#include <assert.h>
#include <stdio.h>
#include <errno.h>


#define START(A) {\
	printf("----------------------------\n");\
	printf("Running test_%s...\n",A);\
}
static inline int check_arrs(int a[], int b[], int size)
{
	int i = 0;
	for(i = 0; i < size; i++) {
		assert(a[i] == b[i]);
		//printf("a[%d]=%d b[%d]=%d\n",i,a[i],i,b[i]);
	}
	printf("\33[0;32mPASSED\33[0m\n");
	return 0;
}

#define mu_assert(test, message) if(!(test)) {printf("%s\n\33[0;31mFAILED\33[0m",message);errno == 0 ? "None" : strerror(errno);}
#define PASSED(A) if(!(A)) {printf("\33[0;32mPASSED\33[0m\n");}

#endif
