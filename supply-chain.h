#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum truckStatus {
    DC,  // At Distribution Center
    IT,  // In Transit
    AS,  // Arrived at Store
    DE	// Decommissioned
};

typedef struct item {

	int ID;
	char * name;
	int quantity;
	double MSRP;

} item;

typedef struct store {

	int ID;
	struct item ** inventory;

} store;

typedef struct truck {

	int ID;
	char * licensePlate;
	struct item ** shipment;
	enum truckStatus status;
	//destination - ? // where is the truck heading (at the moment)
	
} truck;

//structs to define still: customer, distribution center

// need some sort of data structure to act as a "product database"

truck ** listOfTrucks;
item ** dcInventory;
int totalTrucks;
int trucksPerList;
int itemsPerList;
int truckID;
int numProducts;

void createDC();

// Adds a truck to the DC's shipping fleet
int addTruck(char * lp);
int addToCargoList(item ** list, item * item, int quantity);
int addShipment(int id, item ** shipment);
int removeTruck(int id);

// Operations on Trucks, preliminary listing
int sendTruckToStore();
int returnTruck();

// searches to see if the product in question already exists
int searchFor(char * name);

// searches to see if the product in question already exists using product ID (not meant to be manually called)
int searchByID(int id);

//add by name or details (either existing or new product) vs add by ID (existing product?)
//should item ID be autogenerated versus inputted? what about existing products and new products?
int addItemByID(int id);
int addItemByName(char * name, double MSRP);

//move item from one location to another (e.g. distribution center to truck, truck to store, store to customer, etc.)
int addItemTo(item ** origin, item ** destination);
