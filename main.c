#include "supply-chain.h"

void printFleet() {
	
	int i = 0;
	while (listOfTrucks[i] != NULL) {
			printf("%s\n", listOfTrucks[i]->licensePlate);  
		i++;
	}
	
}

int main() {

	createDC();
	
	char * lp1 = "This is License Plate 1";
	addTruck(lp1);
	
	char * lp2 = "License Plate Number 2";
	addTruck(lp2);
	
	printFleet();

	return 0;
}

