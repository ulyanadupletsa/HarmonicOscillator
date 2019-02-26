/* 
 *   File main.c
 *
 *   Contains the main program. The harmonic oscillator configuration 
 *	 is initialized.
 * 	 Then various functions are called:
 *	 1) the evolution function -> evolution(S) and the action data are stored
 *   2) the autocorrelation function -> autocorr()
 *	 3) the binning function -> correlatorbinn()
 *   4) the mean correlator function -> correlatormean()
 *   5) the clusterjackknife function -> clusterjacknife()
 * 	 6) the energy function -> energy()
 */ 


#define MAIN_PROGRAM

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include "global.h"
#include "action.h"
#include "random.h"
#include "statistics.h"

int main(void) {

	FILE *dataAction = fopen("dataAction.txt", "w+");
	
	int k, dataBinLength;
	float *S;
	
	/*Dynamically allocated vectors for action S*/
	S = malloc(Nconf*sizeof(float));

	/*Initialization of the position vector over physical time*/
	xx[0] = -1.0;
	for(k=1; k<N; k++) {
		xx[k] = (-1.0)*xx[k-1];
	}
	
	/*Evolve the Markov chain and calculate the action for each configuration*/
	evolution(S);
	

	/*Print the action values for each configuration*/
	for(k = 0; k < 200; k++) {
		fprintf(dataAction, "%d %f\n", k+1, S[k]);
	}
	free(S);
	fclose(dataAction);

	/*Calculate the autocorrelator to find the correlation length*/
	autocorr();

	/*Calculate the binned correlator: for each of N values we take the
	mean over bin configurations*/
	correlatorbinn();

	/*Print data for correlator graph*/
	correlatormean();

	/*Calculate the clusterized variables*/
	clusterjacknife();

	/*Calculate energy values*/
	energy();





	
	return 0;
}
