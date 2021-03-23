// This module is for user's bat-bowl choice and user's bat-bowl game.
#include "HandCricket.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int bbchoice(){
     char bbchoose[8];
     int upper=6,lower=1;
     int usrinput,compinput,totalscore=0;
     int bbnum=0, usrresult, compresult;
     printf("\nWhat do you want to choose?");
     printf("\nBatting or Bowling? - ");
     scanf("%s", bbchoose);
     if(!strcasecmp(bbchoose,"Batting")){
        bbnum=1;
        printf("\nYou have chosen Batting");
        printf("\nLet's start the game...");
        usrresult = batgame();
        printf("\nYour total score is %d", usrresult);
        printf("\nSo I need %d runs to win from you", ++usrresult);
        printf("\nLet's start again...");
        for ( ; ; ){
            printf("\nEnter your input(1 - 6):");
            scanf("%d", &usrinput);
            compinput=rndnum(lower, upper);
            if (usrinput!=compinput){
                totalscore+=compinput;
                if (usrresult>totalscore){
                    printf("\nYou chose %d and I chose %d.So, my score is %d and I need %d more runs to win\n", usrinput, compinput, totalscore, usrresult-totalscore);
                }
                else if (totalscore>usrresult){
                    printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, (--usrresult), totalscore);
		    printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   L O S E~~~~~~~~~~~~~~~~~~~");
                    printf("\n\nby %d runs\n", totalscore-usrresult);
                    break;
                }
            }
            else if(usrinput==compinput && totalscore==(usrresult-1)){
                 printf("\nHuh it's a tie\n");
            }
            else {
                printf("\nOops!!! I'm out");
                printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, (--usrresult), totalscore);
		printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   W I N~~~~~~~~~~~~~~~~~~~~");
                printf("\n\nby %d runs\n", usrresult-totalscore);
                break;
            }
        }

     }
     else{
        bbnum=0;
        printf("\nYou have chosen Bowling");
        printf("\nLet's start the game...");
        compresult = bowlgame();
        printf("\nMy total score becomes %d", compresult);
        printf("\nSo you need %d runs to win from me", ++compresult);
        printf("\nLet's start again...");
        for ( ; ; ){
            printf("\nEnter your input(1 - 6):");
            scanf("%d", &usrinput);
            compinput=rndnum(lower, upper);
            if (usrinput!=compinput){
                totalscore+=usrinput;
                if (compresult>totalscore){
                    printf("\nYou chose %d and I chose %d.So, your score is %d and you need %d more runs to win\n", usrinput, compinput, totalscore, compresult-totalscore);
                }
                else if (totalscore>compresult){
                    printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, totalscore, (--compresult));
		    printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   W I N~~~~~~~~~~~~~~~~~~~~");
                    printf("\n\nby %d runs\n", totalscore-compresult);
                    break;
                }
            }
            else if(usrinput==compinput && totalscore==(compresult-1)){
                printf("\nHuh it's a tie\n");
            }
            else {
                printf("\nOh yeah!!! You are out");
                printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, totalscore, (--compresult));
		printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   L O S E~~~~~~~~~~~~~~~~~~~~");
                printf("\n\nby %d runs\n", compresult-totalscore);
                break;
            }
          }
     }
     return bbnum;
}
