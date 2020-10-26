#include<stdio.h>

int numberofPassenger = 0;
// To get number of passenger travelling but with added discount
float passengerCost(){
	float adult, child, infant;
	printf("\nEnter number of adults : ");
	scanf("%f",&adult);
	printf("Enter number of children aged below 12 : ");
	scanf("%f",&child);
	printf("Enter number of infants aged below 2: ");
	scanf("%f",&infant);
	numberofPassenger = adult + child;
	adult = adult + 0.7*child;
	return adult;
}
// return number of passenger
int quantityofPassenger(){
	return numberofPassenger;
}
//to select food a passenger wants on board
int food_option()
{
	int opt;
	printf("\n\nSelect on-board meal:\n");
	printf("1.Non-Veg\n2.Veg\n3.None\n");
	printf("Enter your choice:");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			return numberofPassenger*300;
		case 2:
			return numberofPassenger*200;
		case 3:
			return 0;
	}
}

//to select the option for carrying additional luggage

int add_luggage()
{
    int lug;
	int opt;
	printf("\n\nEnter 1. if you are carrying extra luggage else 0 : ");
	scanf("%d",&opt);
	if(opt == 1){
    	printf("\nEnter the amount additional luggage(in Kg): \n");
    	scanf("%d",&lug);
    	return (400*lug);
	}
	else
		return 0;
}
