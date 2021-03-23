// This module is for computer bowling.
#include "HandCricket.h"
#include <stdio.h>
#include <stdlib.h>
int cbowlgame(){
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
       			totalscore+=usrinput;
       			printf("\nYou chose %d and I chose %d.So, your score is %d\n", usrinput, compinput, totalscore);
    		}
    		else {
                        printf("\nYou chose %d and I also chose %d.\n", usrinput, compinput);
       			printf("Oh Yeah!!! You're out");
       			return totalscore;
    		}
  	}
}

