 #include "supply-chain.h"
 
 void createDC() {
 	
 	totalTrucks = 0;
 	numProducts = 0;
 	
 	truckID = 1;
 	trucksPerList = 10;
 	itemsPerList = 10;
 	
 	listOfTrucks = malloc(sizeof(truck*)*trucksPerList);
 	int i;
 	for (i = 0; i < trucksPerList; i++) {
 		listOfTrucks[i] = NULL;
 	}
 	
 	dcInventory = malloc(sizeof(item*)*itemsPerList);
 	for (i = 0; i < itemsPerList; i++) {
 		dcInventory[i] = NULL;
 	}
 }
 
 int searchByID(int id) {
 	return 0;
 }
 
 int addItemByName(char * name, double MSRP) {
 	
 	item *newItem = malloc(sizeof(item));
 	newItem->name = strdup(name);
	newItem->MSRP = MSRP;
 	 	
 	 // need to add to dcInventory
 	 // might need to change later
 	 dcInventory[numProducts] = newItem;
 	 numProducts++;
 	 
 	return 0;
 } 
 
 int addTruck(char * lp) {
 
 	truck * newTruck = malloc(sizeof(truck));
 	newTruck->ID = truckID;
 	newTruck->licensePlate = strdup(lp);
	newTruck->status = DC;
	
	// need to add to listOfTrucks
	listOfTrucks[totalTrucks] = newTruck;
	truckID++;
	totalTrucks++;
	
 	return 0;
 }
 
 int addToCargoList(item ** list, item * item, int quantity) {
 	
 	int i = 0;
 	while (list[i] != NULL) {
 		i++;
 	}
 	
 	list[i] = malloc(sizeof(item));
 	list[i]->ID = item->ID;
 	list[i]->name = strdup(item->name);
// 	strcpy(list[i]->name, item->name);
 	list[i]->quantity = quantity;
 	list[i]->MSRP = item->MSRP; 
 	
 	return 0;
 }
 
 int addShipment(int id, item ** shipment) {
 	//need to search for truck by id first
 	//also need to make sure truck isnt decommissioned
 	
 	//wrong implementation as the char * name wont copy over
//  	listOfTrucks[id-1]->shipment = shipment;

	int i = 0;
	while (shipment[i] != NULL) {
		
		listOfTrucks[id-1]->shipment[i]->ID = shipment[i]->ID;
// 		listOfTrucks[id-1]->shipment.id = shipment.id; use memcpy?
		listOfTrucks[id-1]->shipment[i]->quantity = shipment[i]->quantity;
		listOfTrucks[id-1]->shipment[i]->MSRP = shipment[i]->MSRP;
		
		
		i++;
	}
	
	
 	
 	return 0;
 }
 
 int removeTruck(int id) {
	// need to first see if said truck exists/hasnt been decommissioned already
	
	int i = 0;
	
	while (listOfTrucks[i]->ID != id) {
		i++;
	}
	
	//currently just decommissions the truck - does not remove from database
	//also does not remove from list of trucks either
	listOfTrucks[i]->status = DE;
	
	return 0;
 }