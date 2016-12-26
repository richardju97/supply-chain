 #include "supply-chain.h"
 
 void createDC() {
 	
 	totalTrucks = 0;
 	numProducts = 0;
 	
 	trucksPerList = 10;
 	
 	//need to malloc dcInventory
 	listOfTrucks = malloc(sizeof(truck*)*trucksPerList);
 	int i;
 	for (i = 0; i < trucksPerList; i++) {
 		listOfTrucks[i] = NULL;
 	}	
 }
 
 int addItemByName(char * name, double MSRP) {
 	
 	item *newItem = malloc(sizeof(item));
 	newItem->name = strdup(name);
	newItem->MSRP = MSRP;
 	 	
 	 // need to add to dcInventory
 	 	
 	return 0;
 } 
 
 int addTruck(char * lp) {
 
 	truck * newTruck = malloc(sizeof(truck));
 	newTruck->licensePlate = strdup(lp);
	newTruck->status = DC;
	
	// need to add to listOfTrucks
	listOfTrucks[totalTrucks] = newTruck;
	totalTrucks++;
	
 	return 0;
 }