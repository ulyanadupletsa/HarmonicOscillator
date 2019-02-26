/* 
 *   File clusterjacknife.c
 * 
 * 	 void clusterjacknife()
 * 		routine that reads the dataBinn.txt and the 
 *		dataCorrMean.txt to calculate the clusterized
 * 		data which are stored in the dataCluster.txt file
 *
 */ 



#define CLUSTERJACKNIFE_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"
#include "statistics.h"
#include <math.h>
#include "random.h"


void clusterjacknife (void){

	FILE *dataCorrMean = fopen("dataCorrMean.txt", "r");
	FILE *dataBinn = fopen("dataBinn.txt", "r");
	FILE *dataCluster = fopen("dataCluster.txt", "w");

	int i, j;
	int dataBinLength, NconfBin;
	float cluster;
	float *corrMean, *corrBin;

	dataBinLength = ((Nconf-Nterm)/bin)*N;
	NconfBin = (Nconf-Nterm)/bin;

	corrMean = malloc(N*sizeof(float));
	corrBin = malloc(dataBinLength*sizeof(float));

	/*Scan and store the correlator mean for each of N times*/
	for (i=0; i<N; i++){
		fscanf(dataCorrMean, "%f ", &corrMean[i]);
	}
	fclose(dataCorrMean);

	/*Scan and store binned correlator data*/
	for (i=0; i<dataBinLength; i++){
		fscanf(dataBinn, "%f ", &corrBin[i]);
	}
	fclose(dataBinn);

	/*Generate the jacknife variables for correlator and store them*/
	for (j=0; j<dataBinLength; j+=NconfBin){
		for (i=0; i<NconfBin; i++){
			cluster = corrMean[j/NconfBin]-(corrBin[j+i]-corrMean[j/NconfBin])/(NconfBin-1);
			fprintf(dataCluster, "%f\n", cluster);
		}
	}
	free(corrMean);
	free(corrBin);
	fclose(dataCluster);

}
