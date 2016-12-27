#include "supply-chain.h"

void printFleet() {
	
	printf("\n---------------------\n");  
	printf("Printing Shipping Fleet (All Trucks):\n\n");  
	
	int i = 0;
	while (listOfTrucks[i] != NULL) {
			printf("Truck ID: %d\n", listOfTrucks[i]->ID);  
			printf("License Plate: %s\n", listOfTrucks[i]->licensePlate);  
			printf("Current Status: %u\n\n", listOfTrucks[i]->status);
			
			// if (listOfTrucks[i]->shipment[0] != NULL) {
// 			
// // 				only prints the first item as of now
// 				printf("Current Cargo: %s\n\n", listOfTrucks[i]->shipment[0]->name);   
// 			} else {
// 				printf("No cargo on board.\n\n");
// 			}
			
		i++;
	}
	
	printf("End of Shipping Fleet.\n");  
	printf("---------------------\n\n");  
}

void printDCInventory() {

	printf("\n---------------------\n");  
	printf("Printing DC Inventory (All Items):\n\n");  
	
	int i = 0;
	while (listOfTrucks[i] != NULL) {
// 			printf("Truck ID: %d\n", listOfTrucks[i]->ID);  
			printf("Item Name: %s\n", dcInventory[i]->name);  
			printf("MSRP: $%.2f\n\n", dcInventory[i]->MSRP); 
		i++;
	}
	
	printf("End of DC Inventory.\n");  
	printf("---------------------\n\n");  	
}

int main() {

	createDC();
	
	// basic test case for trucks
	
	char * lp1 = "This is License Plate 1";
	addTruck(lp1);
	
	char * lp2 = "License Plate Number 2";
	addTruck(lp2);
	
	removeTruck(1);
	
	printFleet();
	
	// basic test case for items
	
	char * item1 = "Some Item to be sold";
	addItemByName(item1, 4.99);
	
	char * item2 = "Please buy this product";
	addItemByName(item2, 10.99);

	printDCInventory();
	

	return 0;
}

