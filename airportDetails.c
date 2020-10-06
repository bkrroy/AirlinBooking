#include<stdio.h>
#include<string.h>
// MAXROUTES defines  the number of possible routes the airline reservation is taking
// This is hardcoded
#define MAXROUTES 2
#define MAXFLIGHTSDEDMUM 2 // maximum flight details from Delhi to mumbai

// contants to define cities
#define DEL "DEL" // Delhi city
#define MUM "MUM" // Mumbai city
#define CAL "CAL" // Calcuta city
#define AMD "AMD" // Ahmedabad city
#define BLR "BLR" // Banglore city
#define AMR "AMR" // Amritsar city
#define CAN "CAN" // Chandigarh city
#define MAA "MAA" // Chennai City
#define PAT "PAT" // Patna city
// Currently we have taken only famous cities


// constants to define flight companies
#define INDIGO "Indigo"
#define SPICEJET "Spice Jet"
#define AIRINDIA "Air India"
#define VISTARA "Vistara"
// End of details of flight companies

// The following Structure contains the information of different Airports 
// It contains the information of Arrival and Departure of From one airport to Another Airport
struct AirportPaths{
    char *departure;
    char *arrival;
};

// the following structure contains the information about the flights
struct FlightDetails{
    char *company; // To print the name of the company
    char *flightCode; // To give the code of the fligh
    char *departurTime; // contains the departure time of flight
    char *arrivalTime;// contains the arrival time of flight
    char *flightDuration; // contains flight duration 
    float initialFlightCost; // Displays the initial flight cost --> without any charges of food or anything similar to that
};

// An array of datatype AirportPaths that will contain the total number of airports that are connected
// Every batch of two contains the information about departure and arrival
struct AirportPaths numberOfRoutes[MAXROUTES];

void printFlightDetails(struct FlightDetails *FlightDetails);

void giveValuestoPath(){
    numberOfRoutes[0].departure = strdup(DEL);
    numberOfRoutes[0].arrival = strdup(MUM);

    numberOfRoutes[1].departure = strdup(DEL);
    numberOfRoutes[1].arrival = strdup(CAL);
}

// This function would contain different flight details from delhi to mumbai
void delhi_mumbai(){
    // Array to store flight details for delhi to mumbai
    struct FlightDetails numberofFlights[MAXFLIGHTSDEDMUM];

            // For the first flight 
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("ABCDEF");
    numberofFlights[0].departurTime = strdup("08:20");
    numberofFlights[0].arrivalTime = strdup("10:25");
    numberofFlights[0].flightDuration = strdup("2h 5m");
    numberofFlights[0].initialFlightCost = 3955;

            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("GHIJK");
    numberofFlights[1].departurTime = strdup("06:00");
    numberofFlights[1].arrivalTime = strdup("20:05");
    numberofFlights[1].flightDuration = strdup("14h 5m");
    numberofFlights[1].initialFlightCost = 3900;

    // Calling the function to print the details of the flights
    for(int i = 0; i<MAXFLIGHTSDEDMUM; i++)
        printFlightDetails(numberofFlights + i);
}

void airPortDetails(){
    giveValuestoPath();
    for(int i = 0; i<MAXROUTES; i++){
        printf("Departure : %s\t\t", numberOfRoutes[i].departure);
        printf("Arrival : %s\n\n", numberOfRoutes[i].arrival);
        //using %0.3s here becuse the program was picking up ambigous values if not used
    }
    delhi_mumbai();
}

// Function to print the flight details
void printFlightDetails(struct FlightDetails *flghtDetail){
    
    printf("Airline : %s\t\t\t", flghtDetail->company);
    printf("Flight Code : %s\n", flghtDetail->flightCode);
    printf("Deparure : %s\t", flghtDetail->departurTime);
    printf("Arrival : %s\t\t", flghtDetail->arrivalTime);
    printf("Flight Duration : %s\n", flghtDetail->flightDuration);
    printf("\t\t\tCost : %0.2f\n\n", flghtDetail->initialFlightCost);
}