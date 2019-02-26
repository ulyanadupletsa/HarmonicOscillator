/* 
 *   File correlatormean.c
 *
 *	 void correlatormean()
 *		routine that reads the correlator binned data from
 * 		dataBinn.txt and calculates the mean of the correlator
 * 		over the configuration for each physical time; the new
 * 		data are stored in dataCorrMean.txt
 *
 */ 



#define CORRELATORMEAN_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"
#include <math.h>
#include "random.h"

void correlatormean() {

	FILE *dataBinn = fopen("dataBinn.txt", "r");
	FILE *dataCorrMean = fopen("dataCorrMean.txt", "w");
	
	int k, j, dataBinLength, NconfBin;
	float *corrBin;
	float corrMean;

	dataBinLength = ((Nconf-Nterm)/bin)*N;
	NconfBin = (Nconf-Nterm)/bin;
	corrBin = malloc(dataBinLength*sizeof(float));

	/*Scan and store the binned correlator data*/
	/*Calculate the mean correlator for each physical time*/
	for (k=0; k<dataBinLength; k+=NconfBin){
		corrMean = 0;
		for (j=0; j<NconfBin; j++){
			fscanf(dataBinn, "%f ", &corrBin[k+j]);
			corrMean = corrMean + corrBin[k+j];
		}
		fprintf(dataCorrMean, "%f\n", corrMean/NconfBin);	
	}

	free(corrBin);

	fclose(dataBinn);
	fclose(dataCorrMean);
	correlatorsigma();

}

