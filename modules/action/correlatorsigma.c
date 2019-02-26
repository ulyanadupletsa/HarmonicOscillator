/* 
 *   File correlatorsigma.c
 *
 * 	 void correlatorsigma()
 *		routine that reads through dataCorrMean.txt and 
 * 		dataBinn.txt and calculates the standard deviation
 * 		for the mean correlator data
 *
 */ 



#define CORRELATORSIGMA_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"
#include <math.h>
#include "random.h"

void correlatorsigma (void){
	FILE *dataCorrMean = fopen("dataCorrMean.txt", "r");
	FILE *dataBinn = fopen("dataBinn.txt", "r");
	FILE *dataCorrSigma = fopen("dataCorrSigma.txt", "w");

	int k, i, dataBinLength, NconfBin;
	float sigma;
	float *correlator, *correlatorMean;

	dataBinLength = ((Nconf-Nterm)/bin)*N;
	NconfBin = (Nconf-Nterm)/bin;

	correlator = malloc(dataBinLength*sizeof(float));
	correlatorMean = malloc(N*sizeof(float));

	/*Scan and store correlator data*/
	for(i=0; i<dataBinLength; i++){
		fscanf(dataBinn, "%f ", &correlator[i]);
	}
	fclose(dataBinn);

	/*Scan and store correlator mean data*/
	for(i=0; i<N; i++){
		fscanf(dataCorrMean, "%f ", &correlatorMean[i]);
	}
	fclose(dataCorrMean);

	/*Calculate standard deviation for mean correlator data*/
	for (i=0; i<dataBinLength; i+=NconfBin){
		sigma = 0;
		for(k=0; k<NconfBin; k++){
			sigma += (correlator[i+k]-correlatorMean[i%NconfBin])*(correlator[i+k]-correlatorMean[i%NconfBin]);
		}
		sigma = sigma/(NconfBin*(NconfBin-1));
		fprintf(dataCorrSigma, "%f\n", sqrt(sigma));
	}
	free(correlator);
	free(correlatorMean);
	fclose(dataCorrSigma);
}

