/* 
 *   File ds.c
 *	 
 * 	 float deltas(float y, int j)
 * 		routine that the action variation between two trajectories
 * 		which differ in a point
 *   
 */ 


#define DS_C

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include "global.h"
#include "action.h"
#include "random.h"

float deltas(float y, int j) {
	
	float delta;	

	/*Calculate the action variation when a new point is proposed*/
	delta = (y*y - xx[j]*xx[j])*(M/a + 0.5*M*W*W*a) + (xx[j] - y)*(xx[(j-1+N)%N] + xx[(j+1)%N])*M/a;
	
	return delta;		
}

