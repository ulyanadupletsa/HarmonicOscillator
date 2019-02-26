/* 
 *   File autocorr.c
 *
 * 	 void autocorr()
 * 		routine that calcolates the autocorrelation function
 * 		from the correlator data file; the non thermalized 
 * 		values of the correlator are ignored; the autocorrelator
 * 		data are stored in the dataAutoCorr.txt file
 */ 



#define AUTOCORR_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"
#include <math.h>
#include "random.h"

void autocorr() {

	FILE *dataCorr = fopen("dataCorr.txt", "r");
	FILE *dataAutoCorr = fopen("dataAutoCorr.txt", "w");

	int t, j, k, dataTermLength, n=5;
	float *corr, *autocorr;
	float sum, sumquad, *sumprod;

	dataTermLength = (Nconf-Nterm)*N;
	autocorr = malloc(Ncorr*sizeof(float));
	corr = malloc(dataTermLength*sizeof(float));
	sumprod = malloc(Ncorr*sizeof(float));

	/*Initialize quantities for autocorrelator calculation*/
	sum = 0;
	sumquad = 0;
	for (j=0; j<Ncorr; j++){
		sumprod[j] = 0;
	}

	/*Scan correlator data from file*/
	for (k=0; k<dataTermLength; k++){
		fscanf(dataCorr, "%f ", &corr[k]);
	}
	fclose(dataCorr);

	/*Fix the same correlator for each configuration*/
	for (k=n; k<dataTermLength; k+=N){
		sum = sum + corr[k];
		sumquad = sumquad + corr[k]*corr[k];
	}
	
	sum = sum/(Nconf-Nterm);
	sumquad = sumquad/(Nconf-Nterm);

	/*Calculate the autocorrelation function for correlators at time n*/
	for (t=0; t<Ncorr; t++){
		for (j=n; j<(dataTermLength-t*N); j=j+N){
			sumprod[t] = sumprod[t] + corr[j]*corr[j+t*N];
		}
		autocorr[t] = (sumprod[t]/(Nconf-Nterm-t)-sum*sum)/(sumquad -sum*sum);
		fprintf(dataAutoCorr, "%d %f\n", t+1, autocorr[t]);
	}
	free(corr);
	free(autocorr);
	free(sumprod);
	fclose(dataAutoCorr);
}

