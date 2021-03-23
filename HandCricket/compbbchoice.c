// This module is for computer's bat-bowl choice and computer's bat-bowl game.
#include "HandCricket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cbbchoice(){
    char *cbbchoose[]={"Bat", "Bowl"};
    int lower=1, upper=6, totalscore=0;
    int lowerchoice=0, upperchoice=1;
    int usrresult, usrinput, compinput, compresult;
    char chioce[5];
    strcpy(chioce, cbbchoose[rndnum(lowerchoice, upperchoice)]);
    printf("\nI won the toss");
    printf("\nSo I choose to %s first", chioce);
    printf("\nLet's start the game...");
    if (!strcasecmp(chioce, "Bat"))
    {
        compresult = cbatgame();
        printf("\nMy total score is %d", compresult);
        printf("\nSo you need %d runs to win from me.", ++compresult);
        printf("\nLet's start again...");
        for ( ; ; ){
            printf("\nEnter your input(1 - 6):");
            scanf("%d", &usrinput);
            compinput=rndnum(lower, upper);
            if (usrinput!=compinput){
                totalscore+=usrinput;
                if (compresult > totalscore){
                    printf("\nYou chose %d and I chose %d.So, your score is %d and you need %d more runs to win\n", usrinput, compinput, totalscore, compresult-totalscore);
                }
                else if(totalscore>compresult){
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
                printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, totalscore, (--compresult));
                printf("\nOh yeah!!! You are out");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   L O S E~~~~~~~~~~~~~~~~~~~~");
                printf("\n\nby %d runs\n", compresult-totalscore);
                break;
            }
        }

    }
    else{
        usrresult = cbowlgame();
        printf("\nYour total score is %d", usrresult);
        printf("\nSo, I need %d runs to win from you.", ++usrresult);
        printf("\nLet's start again...");
        for ( ; ; ){
            printf("\nEnter your input(1 - 6):");
            scanf("%d", &usrinput);
            compinput=rndnum(lower, upper);
            if (usrinput!=compinput){
                totalscore+=compinput;
                if (usrresult > totalscore){
                    printf("\nYou chose %d and I chose %d.So, my score is %d and I need %d more runs to win\n", usrinput, compinput, totalscore, usrresult-totalscore);
                }
                else if(totalscore>usrresult){
                    printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, (--usrresult), totalscore);
		    printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   L O S E~~~~~~~~~~~~~~~~~~~~");
                    printf("\n\nby %d runs\n", totalscore-usrresult);
                    break;
                }
            }
            else if (usrinput==compinput && totalscore==(usrresult-1)){
                printf("\nHuh it's a tie\n");
            }
            else {
                printf("\nYou chose %d and I chose %d which makes your total score %d and my total score %d\n", usrinput, compinput, (--usrresult), totalscore);
                printf("\nOops!!! I'm out");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~Y O U   W I N~~~~~~~~~~~~~~~~~~~~");
                printf("\n\nby %d runs\n", usrresult-totalscore);
                break;
            }
        }
    }
    return 0;
}
