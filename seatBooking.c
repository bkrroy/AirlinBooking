#include<stdio.h>

int availableSeat = 108;

//const char*
void seatStatus(){
    printf("Number of Seats Left : %d\n", availableSeat);
}

void updateSeat(int numberOfPassenger){
    availableSeat -= numberOfPassenger;
    printf("************          Seats booked           *************\n");
}