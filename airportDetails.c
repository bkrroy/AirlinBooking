#include<stdio.h>
#include<string.h>
// MAXROUTES defines  the number of possible routes the airline reservation is taking
// This is hardcoded
#define MAXROUTES 2
#define DEL "DEL" // Delhi city
#define MUM "MUM" // Mumbai city
#define CAL "CAL" // Calcuta city
#define DED "DED" // Dehradun city
#define AMD "AMD" // Ahmedabad city
#define BLR "BLR" // Banglore city
#define AMR "AMR" // Amritsar city
#define CAN "CAN" // Chandigarh city
#define MAA "MAA" // Chennai City
#define PAT "PAT" // Patna city
// Currently we have taken only famous cities

// The following Structure contains the information of different Airports 
// It contains the information of Arrival and Departure of From one airport to Another Airport
struct AirportPaths{
    char departure[3];
    char arrival[3];
};

// An array of datatype AirportPaths that will contain the total number of airports that are connected
// Every batch of two contains the information about departure and arrival
struct AirportPaths numberOfRoutes[] = {DEL , MUM, DEL, CAL};

void airPortDetails(){
    // giveRoutes();
    for(int i = 0; i<MAXROUTES; i++){
        printf("Departure : %0.3s\t\t", numberOfRoutes[i].departure);
        printf("Arrival : %0.3s\n", numberOfRoutes[i].arrival);
        //using %0.3s here becuse the program was picking up ambigous values if not used
    }
}