#include<stdio.h>
#include<string.h>
// MAXROUTES defines  the number of possible routes the airline reservation is taking
// This is hardcoded
#define MAXROUTES 8

#define MAXFLIGHTSDELMUM 2 // maximum flight details from Delhi to mumbai
#define MAXFLIGHTSDELCAL 2 // maximum flight details from Delhi to Calcutta
#define MAXFLIGHTSDELBLR 2 // maximum flight details from Delhi to Bangalore
#define MAXFLIGHTSDELMAA 2 // maximum flight details from Delhi to Chennai
#define MAXFLIGHTSMUMDEL 2 // maximum flight details from Mumbai to Delhi
#define MAXFLIGHTSMUMCAL 2 // maximum flight details from Mumbai to Calcutta
#define MAXFLIGHTSMUMBLR 2 // maximum flight details from Mumbai to Bangalore
#define MAXFLIGHTSMUMMAA 2 // maximum flight details from Mumbai to Chennai

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
    
    numberOfRoutes[2].departure = strdup(DEL);
    numberOfRoutes[2].arrival = strdup(BLR);
    
    numberOfRoutes[3].departure = strdup(DEL);
    numberOfRoutes[3].arrival = strdup(MAA);
    
    numberOfRoutes[4].departure = strdup(MUM);
    numberOfRoutes[4].arrival = strdup(DEL);
    
    numberOfRoutes[5].departure = strdup(MUM);
    numberOfRoutes[5].arrival = strdup(CAL);
    
    numberOfRoutes[6].departure = strdup(MUM);
    numberOfRoutes[6].arrival = strdup(BLR);
    
    numberOfRoutes[7].departure = strdup(MUM);
    numberOfRoutes[7].arrival = strdup(MAA);
}

// This function would contain different flight details from delhi to mumbai
void delhi_mumbai(){
    // Array to store flight details for delhi to mumbai
    int i;
    struct FlightDetails numberofFlights[MAXFLIGHTSDELMUM];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("ABCDEF");
    numberofFlights[0].departurTime = strdup("08:20");
    numberofFlights[0].arrivalTime = strdup("10:25");
    numberofFlights[0].flightDuration = strdup("2h 5m");
    numberofFlights[0].initialFlightCost = 3955;

            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("GHIJKW");
    numberofFlights[1].departurTime = strdup("06:00");
    numberofFlights[1].arrivalTime = strdup("20:05");
    numberofFlights[1].flightDuration = strdup("14h 5m");
    numberofFlights[1].initialFlightCost = 3900;

    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSDELMUM; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from delhi to kolkata
void delhi_kolkata(){
    // Array to store flight details for delhi to kolkata
    struct FlightDetails numberofFlights[MAXFLIGHTSDELCAL];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("PQRSTI");
    numberofFlights[0].departurTime = strdup("18:00");
    numberofFlights[0].arrivalTime = strdup("22:45");
    numberofFlights[0].flightDuration = strdup("4h 45m");
    numberofFlights[0].initialFlightCost = 3760;

            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("UVWXYZ");
    numberofFlights[1].departurTime = strdup("8:50");
    numberofFlights[1].arrivalTime = strdup("18:20");
    numberofFlights[1].flightDuration = strdup("9h 30m");
    numberofFlights[1].initialFlightCost = 5750;

    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSDELCAL; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from delhi to bangalore
void delhi_bangalore(){
    // Array to store flight details for delhi to bangalore
    struct FlightDetails numberofFlights[MAXFLIGHTSDELBLR];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("LMNOPM");
    numberofFlights[0].departurTime = strdup("11:00");
    numberofFlights[0].arrivalTime = strdup("16:00");
    numberofFlights[0].flightDuration = strdup("5h 00m");
    numberofFlights[0].initialFlightCost = 4650;

            // For the second flight
    numberofFlights[1].company = strdup(VISTARA);
    numberofFlights[1].flightCode = strdup("ACEGIO");
    numberofFlights[1].departurTime = strdup("12:30");
    numberofFlights[1].arrivalTime = strdup("15:15");
    numberofFlights[1].flightDuration = strdup("2h 45m");
    numberofFlights[1].initialFlightCost = 5000;

    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSDELBLR; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from delhi to chennai
void delhi_chennai(){
    // Array to store flight details for delhi to chennai
    int i;
    struct FlightDetails numberofFlights[MAXFLIGHTSDELMAA];

            // For the first flight
    numberofFlights[0].company = strdup(AIRINDIA);
    numberofFlights[0].flightCode = strdup("BDFHJA");
    numberofFlights[0].departurTime = strdup("10:00");
    numberofFlights[0].arrivalTime = strdup("12:55");
    numberofFlights[0].flightDuration = strdup("2h 55m");
    numberofFlights[0].initialFlightCost = 5000;

            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("KMOQSE");
    numberofFlights[1].departurTime = strdup("17:45");
    numberofFlights[1].arrivalTime = strdup("20:30");
    numberofFlights[1].flightDuration = strdup("2h 45m");
    numberofFlights[1].initialFlightCost = 5000;

    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSDELMAA; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from mumbai to delhi
void mumbai_delhi(){
    // Array to store flight details for mumbai to delhi
    int i;
    struct FlightDetails numberofFlights[MAXFLIGHTSMUMDEL];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("EXYQRR");
    numberofFlights[0].departurTime = strdup("15:35");
    numberofFlights[0].arrivalTime = strdup("17:40");
    numberofFlights[0].flightDuration = strdup("2h 5m");
    numberofFlights[0].initialFlightCost = 4253;

            // For the second flight
    numberofFlights[1].company = strdup(AIRINDIA);
    numberofFlights[1].flightCode = strdup("PRRAKF");
    numberofFlights[1].departurTime = strdup("05:55");
    numberofFlights[1].arrivalTime = strdup("08:05");
    numberofFlights[1].flightDuration = strdup("2h 10m");
    numberofFlights[1].initialFlightCost = 3797;

    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSMUMDEL; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from mumbai to kolkata
void mumbai_kolkata(){
    // Array to store flight details for mumbai to kolkata
    struct FlightDetails numberofFlights[MAXFLIGHTSMUMCAL];

            // For the first flight
    numberofFlights[0].company = strdup(AIRINDIA);
    numberofFlights[0].flightCode = strdup("OTAPWQ");
    numberofFlights[0].departurTime = strdup("06:50");
    numberofFlights[0].arrivalTime = strdup("09:50");
    numberofFlights[0].flightDuration = strdup("3h 0m");
    numberofFlights[0].initialFlightCost = 6938;

            // For the second flight
    numberofFlights[1].company = strdup(VISTARA);
    numberofFlights[1].flightCode = strdup("IUWDWQ");
    numberofFlights[1].departurTime = strdup("11:10");
    numberofFlights[1].arrivalTime = strdup("14:00");
    numberofFlights[1].flightDuration = strdup("2h 50m");
    numberofFlights[1].initialFlightCost = 6967;

    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSMUMCAL; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from mumbai to bangalore
void mumbai_bangalore(){
    // Array to store flight details for mumbai to bangalore
    struct FlightDetails numberofFlights[MAXFLIGHTSMUMBLR];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("CGRNJN");
    numberofFlights[0].departurTime = strdup("18:30");
    numberofFlights[0].arrivalTime = strdup("20:20");
    numberofFlights[0].flightDuration = strdup("1h 50m");
    numberofFlights[0].initialFlightCost = 3481;

            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("FOAAXQ");
    numberofFlights[1].departurTime = strdup("16:20");
    numberofFlights[1].arrivalTime = strdup("18:20");
    numberofFlights[1].flightDuration = strdup("2h 0m");
    numberofFlights[1].initialFlightCost = 3387;

    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSMUMBLR; i++)
        printFlightDetails(numberofFlights + i);
}

// This function would contain different flight details from mumbai to chennai
void mumbai_chennai(){
    // Array to store flight details for mumbai to chennai
    int i;
    struct FlightDetails numberofFlights[MAXFLIGHTSMUMMAA];

            // For the first flight
    numberofFlights[0].company = strdup(VISTARA);
    numberofFlights[0].flightCode = strdup("LNGXIW");
    numberofFlights[0].departurTime = strdup("11:45");
    numberofFlights[0].arrivalTime = strdup("13:45");
    numberofFlights[0].flightDuration = strdup("2h 0m");
    numberofFlights[0].initialFlightCost = 3946;

            // For the second flight
    numberofFlights[1].company = strdup(AIRINDIA);
    numberofFlights[1].flightCode = strdup("CUPRSU");
    numberofFlights[1].departurTime = strdup("12:15");
    numberofFlights[1].arrivalTime = strdup("14:25");
    numberofFlights[1].flightDuration = strdup("2h 10m");
    numberofFlights[1].initialFlightCost = 3820;

    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSMUMMAA; i++)
        printFlightDetails(numberofFlights + i);
}

//currently displays all stored information
void airPortDetails(){	
    giveValuestoPath();
    printf("Departure : %s\t\t", numberOfRoutes[0].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[0].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
    delhi_mumbai();
    printf("--------------------------------------------------------------------------\n");
    printf("Departure : %s\t\t", numberOfRoutes[1].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[1].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
    delhi_kolkata();
    printf("--------------------------------------------------------------------------\n");
    printf("Departure : %s\t\t", numberOfRoutes[2].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[2].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
    delhi_bangalore();
    printf("--------------------------------------------------------------------------\n");
    printf("Departure : %s\t\t", numberOfRoutes[3].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[3].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
    delhi_chennai();
    printf("--------------------------------------------------------------------------\n");
    printf("Departure : %s\t\t", numberOfRoutes[4].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[4].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
	mumbai_delhi();
	printf("--------------------------------------------------------------------------\n");
	printf("Departure : %s\t\t", numberOfRoutes[5].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[5].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
	mumbai_kolkata();
	printf("--------------------------------------------------------------------------\n");
	printf("Departure : %s\t\t", numberOfRoutes[6].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[6].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
	mumbai_bangalore();
	printf("--------------------------------------------------------------------------\n");
	printf("Departure : %s\t\t", numberOfRoutes[7].departure);
    printf("Arrival : %s\n\n", numberOfRoutes[7].arrival); //using %0.3s here becuse the program was picking up ambigous values if not used
	mumbai_chennai();
	printf("--------------------------------------------------------------------------\n");
}

// Function to print the flight details
void printFlightDetails(struct FlightDetails *flghtDetail){
    printf("Airline : %s\t\t\t", flghtDetail->company);
    printf("Flight Code : %s\n", flghtDetail->flightCode);
    printf("Departure : %s\t", flghtDetail->departurTime);
    printf("Arrival : %s\t\t", flghtDetail->arrivalTime);
    printf("Flight Duration : %s\n", flghtDetail->flightDuration);
    printf("\t\t\tCost : %0.2f\n\n", flghtDetail->initialFlightCost);
}
