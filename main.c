#include "supply-chain.h"

void printFleet() {
	
	printf("\n---------------------\n");  
	printf("Printing Shipping Fleet (All Trucks):\n\n");  
	
	int i = 0;
	while (listOfTrucks[i] != NULL) {
			printf("Truck ID: %d\n", listOfTrucks[i]->ID);  
			printf("License Plate: %s\n", listOfTrucks[i]->licensePlate);  
			printf("Current Status: %u\n\n", listOfTrucks[i]->status); 
// 			printf("Current Cargo: %s\n\n", listOfTrucks[i]->licensePlate);   
		i++;
	}
	
	printf("End of Shipping Fleet.\n");  
	printf("---------------------\n\n");  
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

