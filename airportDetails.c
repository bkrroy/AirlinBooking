#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ticketDetails.c"

// MAXROUTES defines  the number of possible routes the airline reservation is taking
// This is hardcoded
#define MAXROUTES 10

#define MAXFLIGHTSDELMUM 2 // maximum flight details from Delhi to mumbai
#define MAXFLIGHTSDELCAL 2 // maximum flight details from Delhi to Calcutta
#define MAXFLIGHTSDELBLR 2 // maximum flight details from Delhi to Bangalore
#define MAXFLIGHTSDELMAA 2 // maximum flight details from Delhi to Chennai
#define MAXFLIGHTSMUMDEL 2 // maximum flight details from Mumbai to Delhi
#define MAXFLIGHTSMUMCAL 2 // maximum flight details from Mumbai to Calcutta
#define MAXFLIGHTSMUMBLR 2 // maximum flight details from Mumbai to Bangalore
#define MAXFLIGHTSMUMMAA 2 // maximum flight details from Mumbai to Chennai
#define MAXFLIGHTSMAABLR 2 // max flight details from chennai to bangalore
#define MAXFLIGHTSMAAMUM 2 // max flight details from chennai to mumbai
// contants to define cities
#define DEL "DEL" // Delhi city
#define MUM "MUM" // Mumbai city
#define CAL "CAL" // Calcuta city
#define BLR "BLR" // Banglore city
#define MAA "MAA" // Chennai City
// Currently we have taken only famous cities


// constants to define flight companies
#define INDIGO "Indigo"
#define SPICEJET "Spice Jet"
#define AIRINDIA "Air India"
#define VISTARA "Vistara"
// End of details of flight companies

// Will Store the final price of the items
float price = 0.0;

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
    int seats[18][6];
    int availableSeat;
};

// An array of datatype AirportPaths that will contain the total number of airports that are connected
// Every batch of two contains the information about departure and arrival
struct AirportPaths numberOfRoutes[MAXROUTES];

void printFlightDetails(struct FlightDetails *FlightDetails);
void print_routeDetails();
int i;
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

    numberOfRoutes[8].departure = strdup(MAA);
    numberOfRoutes[8].arrival = strdup(BLR);

    numberOfRoutes[9].departure = strdup(MAA);
    numberOfRoutes[9].arrival = strdup(MUM);
}

// 1. This function would contain different flight details from delhi to mumbai
struct FlightDetails delhi_mumbai(){
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
    numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;

            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("GHIJKW");
    numberofFlights[1].departurTime = strdup("06:00");
    numberofFlights[1].arrivalTime = strdup("20:05");
    numberofFlights[1].flightDuration = strdup("14h 5m");
    numberofFlights[1].initialFlightCost = 3900;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSDELMUM; i++)
        printFlightDetails(numberofFlights + i);

        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];

}

// 2. This function would contain different flight details from delhi to kolkata
struct FlightDetails delhi_kolkata(){
    // Array to store flight details for delhi to kolkata
    struct FlightDetails numberofFlights[MAXFLIGHTSDELCAL];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("PQRSTI");
    numberofFlights[0].departurTime = strdup("18:00");
    numberofFlights[0].arrivalTime = strdup("22:45");
    numberofFlights[0].flightDuration = strdup("4h 45m");
    numberofFlights[0].initialFlightCost = 3760;
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("UVWXYZ");
    numberofFlights[1].departurTime = strdup("8:50");
    numberofFlights[1].arrivalTime = strdup("18:20");
    numberofFlights[1].flightDuration = strdup("9h 30m");
    numberofFlights[1].initialFlightCost = 5750;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSDELCAL; i++)
        printFlightDetails(numberofFlights + i);



        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 3. This function would contain different flight details from delhi to bangalore
struct FlightDetails delhi_bangalore(){
    // Array to store flight details for delhi to bangalore
    struct FlightDetails numberofFlights[MAXFLIGHTSDELBLR];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("LMNOPM");
    numberofFlights[0].departurTime = strdup("11:00");
    numberofFlights[0].arrivalTime = strdup("16:00");
    numberofFlights[0].flightDuration = strdup("5h 00m");
    numberofFlights[0].initialFlightCost = 4650;
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(VISTARA);
    numberofFlights[1].flightCode = strdup("ACEGIO");
    numberofFlights[1].departurTime = strdup("12:30");
    numberofFlights[1].arrivalTime = strdup("15:15");
    numberofFlights[1].flightDuration = strdup("2h 45m");
    numberofFlights[1].initialFlightCost = 5000;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSDELBLR; i++)
        printFlightDetails(numberofFlights + i);

        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 4. This function would contain different flight details from delhi to chennai
struct FlightDetails delhi_chennai(){
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
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("KMOQSE");
    numberofFlights[1].departurTime = strdup("17:45");
    numberofFlights[1].arrivalTime = strdup("20:30");
    numberofFlights[1].flightDuration = strdup("2h 45m");
    numberofFlights[1].initialFlightCost = 5000;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSDELMAA; i++)
        printFlightDetails(numberofFlights + i);


        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 5. This function would contain different flight details from mumbai to delhi
struct FlightDetails mumbai_delhi(){
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
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(AIRINDIA);
    numberofFlights[1].flightCode = strdup("PRRAKF");
    numberofFlights[1].departurTime = strdup("05:55");
    numberofFlights[1].arrivalTime = strdup("08:05");
    numberofFlights[1].flightDuration = strdup("2h 10m");
    numberofFlights[1].initialFlightCost = 3797;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSMUMDEL; i++)
        printFlightDetails(numberofFlights + i);\

        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 6. This function would contain different flight details from mumbai to kolkata
struct FlightDetails mumbai_kolkata(){
    // Array to store flight details for mumbai to kolkata
    struct FlightDetails numberofFlights[MAXFLIGHTSMUMCAL];

            // For the first flight
    numberofFlights[0].company = strdup(AIRINDIA);
    numberofFlights[0].flightCode = strdup("OTAPWQ");
    numberofFlights[0].departurTime = strdup("06:50");
    numberofFlights[0].arrivalTime = strdup("09:50");
    numberofFlights[0].flightDuration = strdup("3h 0m");
    numberofFlights[0].initialFlightCost = 6938;
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(VISTARA);
    numberofFlights[1].flightCode = strdup("IUWDWQ");
    numberofFlights[1].departurTime = strdup("11:10");
    numberofFlights[1].arrivalTime = strdup("14:00");
    numberofFlights[1].flightDuration = strdup("2h 50m");
    numberofFlights[1].initialFlightCost = 6967;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSMUMCAL; i++)
        printFlightDetails(numberofFlights + i);

        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 7. This function would contain different flight details from mumbai to bangalore
struct FlightDetails mumbai_bangalore(){
    // Array to store flight details for mumbai to bangalore
    struct FlightDetails numberofFlights[MAXFLIGHTSMUMBLR];

            // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("CGRNJN");
    numberofFlights[0].departurTime = strdup("18:30");
    numberofFlights[0].arrivalTime = strdup("20:20");
    numberofFlights[0].flightDuration = strdup("1h 50m");
    numberofFlights[0].initialFlightCost = 3481;
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("FOAAXQ");
    numberofFlights[1].departurTime = strdup("16:20");
    numberofFlights[1].arrivalTime = strdup("18:20");
    numberofFlights[1].flightDuration = strdup("2h 0m");
    numberofFlights[1].initialFlightCost = 3387;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    int i;
    for(i = 0; i<MAXFLIGHTSMUMBLR; i++)
        printFlightDetails(numberofFlights + i);


        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 8. This function would contain different flight details from mumbai to chennai
struct FlightDetails mumbai_chennai(){
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
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
            // For the second flight
    numberofFlights[1].company = strdup(AIRINDIA);
    numberofFlights[1].flightCode = strdup("CUPRSU");
    numberofFlights[1].departurTime = strdup("12:15");
    numberofFlights[1].arrivalTime = strdup("14:25");
    numberofFlights[1].flightDuration = strdup("2h 10m");
    numberofFlights[1].initialFlightCost = 3820;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // Calling the function to print the details of the flights
    for(i = 0; i<MAXFLIGHTSMUMMAA; i++)
        printFlightDetails(numberofFlights + i);


        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 9. flight details from chennai to bangalore
struct FlightDetails chennai_banglore(){
        struct FlightDetails numberofFlights[MAXFLIGHTSMAABLR];
        // For the first flight
    numberofFlights[0].company = strdup(INDIGO);
    numberofFlights[0].flightCode = strdup("INDQQQ");
    numberofFlights[0].departurTime = strdup("10:45");
    numberofFlights[0].arrivalTime = strdup("12:00");
    numberofFlights[0].flightDuration = strdup("1h 15m");
    numberofFlights[0].initialFlightCost = 3246;
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
        // For the second flight
    numberofFlights[1].company = strdup(SPICEJET);
    numberofFlights[1].flightCode = strdup("JETRSU");
    numberofFlights[1].departurTime = strdup("15:15");
    numberofFlights[1].arrivalTime = strdup("17:00");
    numberofFlights[1].flightDuration = strdup("1h 45m");
    numberofFlights[1].initialFlightCost = 3020;
    numberofFlights[1].availableSeat=108;
    for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // calling the function to print the details of the flight
    for(int i = 0; i<MAXFLIGHTSMAABLR; i++)
        printFlightDetails(numberofFlights + i);


        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}

// 10. Flight Details from chennai to mumbai
struct FlightDetails chennai_mumbai(){
        struct FlightDetails numberofFlights[MAXFLIGHTSMAAMUM];
        // For the first flight
    numberofFlights[0].company = strdup(AIRINDIA);
    numberofFlights[0].flightCode = strdup("AIRQQQ");
    numberofFlights[0].departurTime = strdup("20:30");
    numberofFlights[0].arrivalTime = strdup("23:30");
    numberofFlights[0].flightDuration = strdup("3h 30m");
    numberofFlights[0].initialFlightCost = 3546;
	numberofFlights[0].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[0].seats[i][j]=0;
        // For the second flight
    numberofFlights[1].company = strdup(VISTARA);
    numberofFlights[1].flightCode = strdup("ARAQWE");
    numberofFlights[1].departurTime = strdup("15:15");
    numberofFlights[1].arrivalTime = strdup("17:00");
    numberofFlights[1].flightDuration = strdup("1h 45m");
    numberofFlights[1].initialFlightCost = 3320;
	numberofFlights[1].availableSeat=108;
	for(i=0;i<18;i++)
		for(int j=0;j<6;j++)
			numberofFlights[1].seats[i][j]=0;
    // calling the function to print the details of the flight
    for(int i = 0; i<MAXFLIGHTSMAAMUM; i++)
        printFlightDetails(numberofFlights + i);

        int chosenFlight;
        printf("Enter the Chosen flight : ");
        scanf("%d",&chosenFlight);

        if(chosenFlight == 1)
                return numberofFlights[0];
        else
                return numberofFlights[1];
}


// Function to print the flight details
void printFlightDetails(struct FlightDetails *flghtDetail){
    printf("-----------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Airline : %s\t\t\t", flghtDetail->company);
    printf("Flight Code : %s\n", flghtDetail->flightCode);
    printf("Departure : %s\t", flghtDetail->departurTime);
    printf("Arrival : %s\t\t", flghtDetail->arrivalTime);
    printf("Flight Duration : %s\n", flghtDetail->flightDuration);
    printf("\t\t\tCost : %0.2f\n\n", flghtDetail->initialFlightCost);
}


void seatDisplay(struct FlightDetails temp){
    printf("     A B C    D E F\n\n");
    for(int i=0;i<18;i++){
    	printf("%2d   ",i+1);
		for(int j=0;j<6;j++){
			if(j==3)
			{
				printf("   ");
			}
			if(temp.seats[i][j]==0)
			{
				printf("- ");
			}
			else
			{
				printf("X ");
			}
		}
		printf("\n");
	}
}
void bookSeats(struct FlightDetails *temp)
{
	int r,c1;
	char c;
	for(int i=0;i<quantityofPassenger();i++)
	{
		X:
		printf("\nFor passenger %d:\n",i+1);
		printf("Enter row:");
		scanf("%d",&r);
		printf("Enter column:");
		scanf(" %c",&c);
		r--;
		c1=c-65;
		if(temp->seats[r][c1]==0)
		{
			temp->seats[r][c1]=1;
		}
		else
		{
			printf("Seat has already been booked!");
			goto X;
		}
	}
}
void seatStatus(struct FlightDetails temp)
{
	printf("Number of Seats Left : %d\n", temp.availableSeat);
}
void updateSeat(struct FlightDetails *temp){
    temp->availableSeat =temp->availableSeat-quantityofPassenger();
    printf("************          Seats booked           *************\n");
    
}

// Function to call food and luggage function
void call_food_and_luggage(){
       price = price + (float)food_option();
        printf("\t\tCurrent Price : %0.2f\n", price);
        price = price + (float)add_luggage();
        printf("\t\tCurrent Price : %0.2f\n", price); 
}

// Function to call the seat displaying program
void call_seats(struct FlightDetails temp){
        seatDisplay(temp);
        bookSeats(&temp);
        updateSeat(&temp);
        seatDisplay(temp);
        seatStatus(temp);       
}

// Function to print the Route Details only
void print_routeDetails(){
        giveValuestoPath();
        for(int i = 0; i<MAXROUTES; i++){
                printf("%d  ",i+1);
                printf("Departure: %s\t\t",numberOfRoutes[i].departure);
                printf("Arrival : %s\n", numberOfRoutes[i].arrival);
                printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
        }
        int option;
        printf("Enter the Route : \n");
        scanf("%d",&option);
		struct FlightDetails temp;
        switch(option){
                case 1: temp = delhi_mumbai();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
                                        call_food_and_luggage();
                                        call_seats(temp);
                break;
                case 2: temp = delhi_kolkata();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 3: temp = delhi_bangalore();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 4: temp = delhi_chennai();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 5: temp = mumbai_delhi();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 6: temp = mumbai_kolkata();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 7: temp = mumbai_bangalore();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 8: temp = mumbai_chennai();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 9: temp = chennai_banglore();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
                case 10: temp = chennai_mumbai();
                		price=temp.initialFlightCost;
                		printf("%0.2f\n", price);
				        price = price*passengerCost();
				        call_food_and_luggage();
				        call_seats(temp);
                break;
        }
        
        printf("***************    Seat(s) Booked   ***************\n");
        printf("******    THANK YOU FOR USING OUR SERVICES ********\n");
}



// Menu driven function
void onlyShowRoute(){
        int opt;
        printf("\nEnter 1. To Display Routes\n");
        printf("Enter 2. To Book Tickets\n");
        printf("Enter 3. To exit\n");
        printf("Enter Option : ");
        scanf("%d",&opt);

        if(opt == 1){
                giveValuestoPath();
                for(int i = 0; i<MAXROUTES; i++){
                        printf("%d  ",i+1);
                        printf("Departure: %s\t\t",numberOfRoutes[i].departure);
                        printf("Arrival : %s\n", numberOfRoutes[i].arrival);
                        printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
                }
                onlyShowRoute();
        }
        else if(opt == 2){
                print_routeDetails();
        }
        else if(opt == 3){
                printf("\n\t\t........Thank you For Using our Portal........");
        }
        else{
                printf("Enter Valid Option......\n");
                onlyShowRoute();
        }
}