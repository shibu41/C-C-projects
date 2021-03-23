// This is the main driver module.
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int rndnum(int lower, int upper);
void toss();
int bbchoice();
void ready();
int batgame();
int bowlgame();
int cbbchoice();
int cbatgame();
int cbowlgame();

int cbatgame(){
    	int upper=6,lower=1;
    	int usrinput,compinput,totalscore=0;
  	for ( ; ; ){
    		printf("\nEnter your input(1 - 6):");
    		scanf("%d", &usrinput);
		if (usrinput > 6){
                        printf("Enter a number less than 6!!!");
                        continue;
                }
    		compinput = rndnum(lower, upper);
    		if (usrinput != compinput){
       			totalscore+=compinput;
       			printf("\nYou chose %d and I chose %d.So, my score becomes %d\n", usrinput, compinput, totalscore);
    		}
    		else {
                        printf("\nYou chose %d and I also chose %d.\n", usrinput, compinput);
       			printf("Oh no!!! I am out");
       			return totalscore;
    		}
  	}
}

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

int batgame(){
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
       			printf("Oh yeah!!! You are out");
       			return totalscore;
    		}
  	}
}

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


int rndnum(int lower, int upper)
{
    int i;
        srand(time(0));
        int num = (rand() % (upper - lower + 1)) + lower;
        return num;
}

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

int main(){
    toss();
    return 0;
}