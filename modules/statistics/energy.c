/* 
 *   File energy.c
 * 
 * 	 void energy()
 *		routine to calculate 
 *
 * 		1) the difference in energy between
 * 		the fundamental and the first excited levels with 
 *		the relative uncertainty
 * 		
 *		2) the matrix element with the associated uncertainty
 * 
 * 		Errors are calculated implementing the jackknife method
 *
 */ 



#define ENERGY_C

#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"
#include "statistics.h"
#include <math.h>
#include "random.h"


void energy (void){

	FILE *dataCorrMean = fopen("dataCorrMean.txt", "r");
	FILE *dataCluster = fopen("dataCluster.txt", "r");
	FILE *dataEnergy = fopen("dataEnergy.txt", "w");
	FILE *dataMatrixR = fopen("dataMatrixR.txt", "w");

	int i, j, index, dataBinLength, NconfBin;
	float value, x;
	float *corrMean, *energy, *cluster, *encluster, *sigmaEnergy, *Rmean, *Rcluster, *sigmaR;

	dataBinLength = ((Nconf-Nterm)/bin)*N;
	NconfBin = (Nconf-Nterm)/bin;

	corrMean = malloc(N*sizeof(float));
	energy = malloc(N*sizeof(float));
	cluster = malloc(dataBinLength*sizeof(float));
	encluster = malloc(dataBinLength*sizeof(float));
	sigmaEnergy = malloc(N*sizeof(float));
	Rmean = malloc(N*sizeof(float));
	Rcluster = malloc(dataBinLength*sizeof(float));
	sigmaR = malloc(N*sizeof(float));

	/*Scan and store meanCorr data*/
	for(i=0; i<N; i++){
		fscanf(dataCorrMean, "%f", &corrMean[i]);
	}
	fclose(dataCorrMean);

	/*Calculate the mean energy values from avareged correlators*/
	for (i=1; i<N-1; i++){
    	x = (corrMean[i+1]+corrMean[i-1])/(2*corrMean[i]);
    	if (x>=1){
    		energy[i] = log(x+sqrt(x*x-1))/a;
    	}
    	else{
    		index = i; /*Index is the number of the time at which to stop*/
    		break;
    	}
    }

    /*Scan and store clustered correlator values to calculate the clusterized energy values*/
    for(i=0; i<dataBinLength; i++){
    	fscanf(dataCluster, "%f", &cluster[i]);
    }
    fclose(dataCluster);

    for (j=1; j<index; j++){
		for (i=0; i<NconfBin; i++){
			x = (cluster[i+NconfBin*(j+1)]+cluster[i+NconfBin*(j-1)])/(2.0*cluster[i+NconfBin*j]);
			if (x>=1){
				encluster[i+NconfBin*j] = log(x+sqrt(x*x-1))/a;
			}
			else{
				break;
			}
		}
	}
	free(cluster);

	/*Calculate sigma for energy values*/
	for(i=1; i<index; i++){
		value = 0;
		for(j=0; j<NconfBin; j++){
			value += (encluster[j+NconfBin*i]-energy[i])*(encluster[j+NconfBin*i]-energy[i]);
		}
		sigmaEnergy[i] = value*(NconfBin-1)/NconfBin;
		fprintf(dataEnergy, "%f +- %f \n", energy[i], sqrt(sigmaEnergy[i]));
	}
	free(sigmaEnergy);
	fclose(dataEnergy);

	/*Calculate the matrix element*/
	for (i=1; i<index; i++){
		for(j=0; j<NconfBin; j++){
			x = (float)((N/2)-i)*encluster[j+NconfBin*i]*a;
			Rcluster[j+NconfBin*i] = cluster[j+NconfBin*i]/(2*cosh(x))*exp((float)(N/2.0)*encluster[j+NconfBin*i]*a);
		}
	}
	free(encluster);

	/*Calculate the mean value of the matrix element*/
	for(i=1; i<index; i++){
		Rmean[i] = corrMean[i]/(2*cosh(energy[i]*a*(float)(N/2.0-i)))*exp((float)(N/2.0)*energy[i]*a);
	}
	free(corrMean);
	free(energy);
	
	/*Calculate the standard deviation for the mean matrix element*/
	for(i=1; i<index; i++){
		value=0;
		for(j=0; j<NconfBin; j++){
			value = value + (sqrt(Rcluster[j+NconfBin*i])-sqrt(Rmean[i]))*(sqrt(Rcluster[j+NconfBin*i])-sqrt(Rmean[i]));
		}
		sigmaR[i] = value*(NconfBin-1)/NconfBin;
		fprintf(dataMatrixR, "%f %f \n", sqrt(Rmean[i]), sqrt(sigmaR[i]));
	}
	free(Rmean);
	free(Rcluster);

	fclose(dataMatrixR);
}
