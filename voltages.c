/* Voltages
Fall 2018
Mikita Popel */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// This program scans in a collection of voltages scanned in from a .dat file and outputs pertinent information for the energy usage
int main(void) {
	int voltages[71];									//creating variables
	double totalVoltage = 0;
	double meanVoltage, tenPercentMean, fifteenPercentMean, tenPercentLess, fifteenPercentLess;
	bool coma = 0;
	int i;

	for (i = 0; i < 72; i++){							//scanning in the voltages
		scanf("%d", &voltages[i]);
		totalVoltage = totalVoltage + voltages[i];
	}

	meanVoltage = totalVoltage / i;						//calculating values for use later on
	tenPercentMean = meanVoltage*.1;
	fifteenPercentMean = meanVoltage*.15;
	tenPercentLess = meanVoltage - tenPercentMean;
	fifteenPercentLess = meanVoltage - fifteenPercentMean;

	printf("EGRE245 Project #5 Spring 2015 - Mikita Popel\n\n");
	printf("Number of voltages: %d\n", i);
	printf("Mean voltage: %.2lf (10%% of mean: %.2lf; 15%% of mean: %.2lf)\n", meanVoltage, tenPercentMean, fifteenPercentMean);
	printf("Brownout threshold: 107.04\n\n");

	printf("hours that vary >= 10%% from mean:\n  ");
	for (i = 0; i < 72; i++){
		if (voltages[i] <= tenPercentLess){
			if(coma){
			printf(",");
			}
			printf("%d", i+1);
			coma = 1;
		}
	}

	printf("\nhours of neighbors that vary >= 15%% of mean:\n  ");
	coma = 0;
	for (i = 0; i < 72; i++){
		if(i<71){
			if (abs(voltages[i] - voltages[i+1])>= fifteenPercentMean ){
				if(coma){
				printf(",");
				}
				printf("(%d,%d)", i+1, i+2);
				coma = 1;
			}
		}
	}

	printf("\nhours brownout occurred:\n  ");
	coma = 0;
	for (i = 0; i < 72; i++){
		if (voltages[i] <= 107.04){
			if(coma){
			printf(",");
			}
			printf("%d", i+1);
			coma = 1;
		}
	}
	return 0;
}
