#include<stdio.h>
//to select food a passenger wants on board
int food_option()
{
	int opt;
	printf("\nSelect on-board meal:\n");
	printf("1.Non-Veg\n2.Veg\n3.None\n");
	printf("Enter your choice:");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			return 300;
		case 2:
			return 200;
		case 3:
			return 0;
	}
}

//to select the option for carrying additional luggage
int add_luggage()
{
    int lug;
    printf("\nEnter the amount additional luggage(in Kg):\n");
    scanf("%d",&lug);
    return (400*lug);
}
