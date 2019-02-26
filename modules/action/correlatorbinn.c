/* 
 *   File correlatorbinn.c
 * 	 
 * 	 void correlatorbinn()
 * 		routine that reads the dataCorr.txt file and produces
 * 		a dataBinn.txt file in which the binned correlator 
 * 		data are stored
 *
 */ 



#define CORRELATORBINN_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"
#include <math.h>
#include "random.h"

void correlatorbinn() {

	FILE *dataCorr = fopen("dataCorr.txt", "r");
	FILE *dataBinn = fopen("dataBinn.txt", "w");

	int k, j, t, dataTermLength, dataBinLength;
	float binmean;
	float *corr;

	dataTermLength = (Nconf-Nterm)*N;
	dataBinLength = ((Nconf-Nterm)/bin)*N*bin;
	corr = malloc(dataTermLength*sizeof(float));

	/*Scan and store correlator data*/
	for (k=0; k<dataTermLength; k++){
		fscanf(dataCorr, "%f ", &corr[k]);
	}
	fclose(dataCorr);

	/*Take the mean every bin configurations for fixed t*/
	for (t=0; t<N; t++){
		for (k=t; k<dataBinLength; k+=(bin*N)){
			binmean = 0;
			for (j=0; j<bin; j++){
				binmean += corr[k+j*N];
			}
			fprintf(dataBinn, "%f\n", binmean/bin);
		}
	}
	free(corr);
	fclose(dataBinn);
}





