/* 
 *   File oa.c
 * 
 *	 float action(void)
 * 		routine that calculates the action for a given trajectory	
 *
 */ 



#define OA_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"


float action(void) {
	float S;
	int i;
	
	S = 0;
	/*At fixed configuration, calculate the action*/
	for(i=0; i < N; i++) {
		S = S + 0.5*M*(xx[(i+1)%N] - xx[i])*(xx[(i+1)%N] - xx[i])/a + 0.5*a*M*W*W*(xx[i]*xx[i]);
	}

	return S;
}

