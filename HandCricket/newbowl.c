// This module is for user bowling.
#include "HandCricket.h"
#include <stdio.h>
#include <stdlib.h>
int bowlgame(){
    	int upper=6,lower=1;
    	int usrinput,compinput,totalscore=0;
  	for ( ; ; ){
    		printf("\nEnter your input(1 - 6):");
    		scanf("%d", &usrinput);
		if (usrinput > 6){
                        printf("Enter a number less than 6!!!");
                        continue;
                }
    		compinput=rndnum(lower, upper);
    		if (usrinput!=compinput){
       			totalscore+=compinput;
       			printf("\nYou chose %d and I chose %d.So, my score is %d\n", usrinput, compinput, totalscore);
    		}
    		else {
                        printf("\nYou chose %d and I also chose %d.\n", usrinput, compinput);
       			printf("Oops!!! I'm out");
       			return totalscore;
    		}
  	}
}
