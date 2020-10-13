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
