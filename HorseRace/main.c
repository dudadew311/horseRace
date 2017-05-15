//  Created by:		Raul Diaz, Alejandra Valencia
//  Created on:		9/24/15
//	Descriptin:		Morse and the Horses


#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system ("pause")
#define CLS system ("clear")
#define FLUSH fflush(stdin)
#define SIZE 300
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int bet(int *, int *, int *);
void depositMoney(int *, int *);
void displayCash(int , int);
void displayHistory(int[], int);
void displayMenu(int , int);
void displayOdds();
void displayWinner(int);
void exitProgram ();
int generateRandomNumber();
char getChoice(int, int);
int getWinner();
void withdrawMoney(int *, int *);

int main() {
	int wallet = 0, bank = 300, counter = 0, history[SIZE] = {0};
	char choice;
	do {
		CLS;
		choice = getChoice(wallet, bank);
		switch (choice){
			case 'A': //Bet on a horse
				history[counter++] = bet(&wallet, &bank, &counter);
				break;
			case 'B': //Deposit money into bank
				depositMoney(&wallet, &bank);
				break;
			case 'C': //Withdraw money into wallet
				withdrawMoney(&wallet, &bank);
				break;
			case 'D': //Display past winners
				displayHistory(history, counter);
				break;
			case 'E': //Quit message
				exitProgram();
				break;
			default:
			break;
		} //end switch
	} while (choice != 'E');
	return 0;
} //end main

int bet(int *w, int *b, int *c){
	int amount = 0, selection, winner = 0;
	CLS;
	displayOdds();
	displayCash( *w , *b);
	
	printf("Pick a horse from the chart: ");
	scanf("%i", &selection); FLUSH;
	printf("\nHow much would u like to bet? ");
	scanf("%i", &amount); FLUSH;
	
	if (amount < *w){
		CLS;
		printf("\n\n\tAnd they are off!!!\n\n");
		PAUSE;
		winner = getWinner();
		if (winner == selection){
			printf("\n");
			switch (winner){
				case 1:
					*w = *w + amount * 2;
					printf("\tYOU WIN $%i !!!!!\n", amount * 2);
					break;
				case 2:
					*w = *w + amount * 5;
					printf("\tYOU WIN $%i !!!!!\n", amount * 5);
					break;
				case 3:
					*w = *w + amount * 10;
					printf("\tYOU WIN $%i !!!!!\n", amount * 10);
					break;
				case 4:
					*w = *w + amount * 15;
					printf("\tYOU WIN $%i !!!!!\n", amount * 15);
					break;
				case 5:
					*w = *w + amount * 50;
					printf("\tYOU WIN $%i !!!!!\n", amount * 50);
					break;
				case 6:
					*w = *w + amount * 20;
					printf("\tYOU WIN $%i !!!!!\n", amount * 20);
					break;
				case 7:
					*w = *w + amount * 10;
					printf("\tYOU WIN $%i !!!!!\n", amount * 20);
					break;
				case 8:
					*w = *w + amount * 5;
					printf("\tYOU WIN $%i !!!!!\n", amount * 5);
					break;
				case 9:
					*w = *w + amount * 3;
					printf("\tYOU WIN $%i !!!!!\n", amount * 3);
					break;
					
			}// end switch
		} else {
			
			*w = *w - amount;
			printf("\n\tYou Lose, Better Luck Next Time!!\n");
		}
		
	} else {
		*c = *c - 1;
		printf("\n\tYou do not have enough money, withdraw from bank or go home!!\n");
	}
	displayWinner(winner);
	PAUSE;
	return winner;
}//End function bet function

void depositMoney(int *w, int *b){
	int amount = 0;
	CLS;
	displayCash(*w, *b);
	printf("How much would you like to deposit? ");
	scanf("%i", &amount);
	if (amount < *w){
		*b = *b + amount;
		*w = *w - amount;
		printf("\n\tNew Balance:\n\n");
		displayCash(*w, *b);
		
	} else
		printf("\tINSUFFICIENT FUNDS !!!!!!\n\n");
	PAUSE;
}//End depositMoney function

void displayCash(int w, int b){
	printf("\tBank: $%i\t\tWallet: $%i\n\n", b, w);
} //end displayCash function

void displayHistory(int h[], int c){
	int i;
	CLS;
	for (i = 0; i < c; i++) {
		printf("Race: %i. ", i+1 );
		displayWinner(h[i]);
	} //end for
	PAUSE;
} //end displayHistory function

void displayMenu(int w, int b) {
	
	printf("\n");
	printf("\t===========================================\n");
	printf("\t===================MENU====================\n");
	printf("\tA). BET ON A HORSE AND RACE................\n");
	printf("\tB). DEPOSIT MONEY TO BANK..................\n");
	printf("\tC). WITHDRAW MONEY FROM BANK...............\n");
	printf("\tD). DISPLAY PAST WINNERS...................\n");
	printf("\tE). EXIT PROGRAM...........................\n");
	printf("\t===========================================\n");
	printf("\t===========================================\n\n");
	displayCash(w, b);
	printf("Enter your decesion: ");
} //End displayMenu function

void displayOdds(int w, int b){
	printf("||==============||=============||===============||=============||\n");
	printf("||   NAME       ||   PAYOUT    ||    NAME       || PAYOUT      ||\n");
	printf("||==============||=============||===============||=============||\n");
	printf("|| 1.Lady Bug   || Payout 2-1  || 6.Spider Man  || Payout 20-1 ||\n");
	printf("|| 2.Car Guy    || Payout 5-1  || 7.Salchiipapa || Payout 10-1 ||\n");
	printf("|| 3.Lucky Girl || Payout 10-1 || 8.Flower Girl || Payout  5-1 ||\n");
	printf("|| 4.Lady Gaga  || Payout 15-1 || 9.Soccer Love || Payout  3-1 ||\n");
	printf("|| 5.Ugly Boy   || Payout 50-1 ||               ||             ||\n");
	printf("||==============||=============||===============||=============||\n\n");
	
}//End displayOdds Function

void displayWinner(int w){
	switch (w){
		case 1:
			printf("\tWinner was Lady Bug\n");
			break;
		case 2:
			printf("\tWinner was Car Guy\n");
			break;
		case 3:
			printf("\tWinner was Lucky Girl\n");
			break;
		case 4:
			printf("\tWinner was Lady Gaga\n");
			break;
		case 5:
			printf("\tWinner was Ugly Guy\n");
			break;
		case 6:
			printf("\tWinner was Spider Man\n");
			break;
		case 7:
			printf("\tWinner was Salchiipa\n");
			break;
		case 8:
			printf("\tWinner was Flower Girl\n");
			break;
		case 9:
			printf("\tWinner was Soccer Love\n");
			break;
	} //end switch
} //end function

void exitProgram (){
	int height = 15, space = 0, stars, line;
	CLS;
	for (line = 0;line < height; line++){
		while (space < height){
			printf(" ");
			space++;
		} //end while
		for (stars = 0;stars < line;stars++){
			printf("$ ");
			space = 0;
		} //end inner for
		printf("\n");
		space = line;
		stars = 0;
	} //end outer for
	printf("\nThanks for using this Program!!!\n\n");
	PAUSE;
}//End exitProgram function

int generateRandomNumber() {
	int randomNumber;
	srand((unsigned)time(NULL));
	randomNumber = rand() % 100 + 1;
	return randomNumber;
} //End generateRandomNumber function

char getChoice(int w, int b){
		
	char result;
	displayMenu(w, b);
	scanf(" %c", &result); FLUSH;
	result = toupper(result);
		
	return result;
}//End getChoice function

int getWinner(){
	int winner = 0, randomNumber;
	randomNumber = generateRandomNumber();
	if (randomNumber <= 30)
		winner = 1;
	else if (randomNumber <= 40)
		winner = 2;
	else if (randomNumber <= 48)
		winner = 3;
	else if (randomNumber <= 54)
		winner = 4;
	else if (randomNumber <= 56)
		winner = 5;
	else if (randomNumber <= 60)
		winner = 6;
	else if (randomNumber <= 68)
		winner = 7;
	else if (randomNumber <= 78)
		winner = 8;
	else if (randomNumber <= 100)
		winner = 9;
	return winner;
} //end getWinner function

void withdrawMoney(int *w, int *b){
	int amount = 0;
	CLS;
	displayCash(*w, *b);
	printf("How much would you like to withdraw? ");
	scanf("%i", &amount);
	if (amount < *b){
		*b = *b - amount;
		*w = *w + amount;
		printf("\n\tNew Balance:\n\n");
		displayCash(*w, *b);
	} else
		printf("\tINSUFFICIENT FUNDS !!!!!!\n\n");
	PAUSE;
} //End withdrawMoney function
