// This module is for tossing.
#include "HandCricket.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void toss(){
     	char choice;
     	int userchoice,compchoice,result;
     	int lower=0,upper=10;
     	printf("Welcome to the game of HandCricket");
     	printf("\nChoose Odd(O) or Even(E):");
     	choice = getchar();
     	printf("Now choose any number between 1 to 10:");
     	scanf("%d", &userchoice);
	while (userchoice > 10){
		printf("Please enter a number between 1 to 10!!!\n");
		scanf("%d", &userchoice);
	}
     	compchoice=rndnum(lower, upper);
     	result=userchoice+compchoice;

	if(toupper(choice)=='E' && result%2==0){
        	printf("You won the toss!!!");
       	 	printf("\nYour choice was %d and my choice was %d which resulted in %d which is Even", userchoice, compchoice, result);
        	bbchoice();
     	}

	else if (toupper(choice)=='O' && result%2!=0){
        	printf("You won the toss!!!");
        	printf("\nYour choice was %d and my choice was %d which resulted in %d which is Odd", userchoice, compchoice, result);
        	bbchoice();
     	}

	else if (toupper(choice)=='E' && result%2!=0){
        	printf("Sorry you lose the toss");
       		printf("\nYour choice was %d and my choice was %d which resulted in %d which is Odd", userchoice, compchoice, result);
        	cbbchoice();
     	}

	else if (toupper(choice)=='O' && result%2==0){
      		printf("Sorry you lose the toss");
        	printf("\nYour choice was %d and my choice was %d which resulted in %d which is Even", userchoice, compchoice, result);
        	cbbchoice();
     	}
}
