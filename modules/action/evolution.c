/* 
 *   File evolution.c
 *
 *   void evolution (float s[])
 *		routine that evolves the intial configuration of the harmonic oscillator 
 * 		provided in main.c and stores in a dataCorr.txt file the correlator data
 */ 





#define EVOLUTION_C

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include "global.h"
#include "action.h"
#include "random.h"

void evolution(float S[]) {

	FILE *dataCorr = fopen("dataCorr.txt", "w");

	int i, j, k;
	float y;
	float delta;
	float corr;
	float *R;
	R = malloc((2*N)*sizeof(float));
	
	for(i = 0; i < Nconf; i++) {
		
		/*Generate a vector of 2N random numbers and we'll use N for 
		physical evolution and N for accept/reject step*/
		ranlxs(R, 2*N);		
		 
		/*Each trajectory at a time is evolved*/
		for(j = 0; j < N; j++){
			y = xx[j] + 2.0*D*(R[2*j]- 0.5);	
			delta = deltas(y, j);
			if ((delta<0) || (exp(-delta)>=R[2*j+1])){
				xx[j] = y; 
			}
		}
		/*Calculate the action for each trajectory*/
		S[i] = action();

		/*When data are termalized, it's sensible to compute the 
		correlator*/
		if (i>Nterm){
			for (j=0; j<N; j++){ 
				corr = 0;
				for (k=0; k<N; k++){
					corr = corr + (xx[k]*xx[(k+j)%N]);
				}
				/*The correlator data are printed so each block of N
				values corresponds to the same trajectory*/
				fprintf(dataCorr, "%f\n", corr/N);
			}
		}
	}

	free(R);
	fclose(dataCorr);
	
}

