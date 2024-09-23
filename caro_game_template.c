/*
	You will code a 2-player caro game using user input or graphic add-on
	Find the " // Write you code here " and start improve the game by coding yourself or with a group
*/

#include <stdio.h>
#include <stdlib.h>

void print_menu();
int make_choice(int min, int max);
void play_game();
void load_game();
void show_top_player();


int main(void){
	void (*funs[4])(void) = {NULL, &play_game, &load_game, &show_top_player};
	int choice;

	do {
		choice = make_choice(0, 3);
		if (choice){
			funs[choice]();
			printf("\nPress Enter to return to the menu.");
			getchar();
		}
	}
	while (choice);

	return 0;
}

void print_menu(){
	system("cls"); // "cls" -> windows ; "clear" -> mac, linux
	printf("CARO GAME\n");
	printf("---------------------------\n");
	printf("1. Play game\n");
	printf("2. Load game\n");
	printf("3. Show top player\n");
	printf("0. Exit\n");
}

int make_choice(int min, int max){
	int not_valid = 1, num, scanf_ret;
	char c;

	print_menu();
	fflush(stdin);
	do {
		printf("\nEnter your choice: ");
		scanf_ret = scanf("%d%c", &num, &c);
		if (scanf_ret < 2 || c != '\n'){
			print_menu();
			printf("\nYour choice is not valid. Please try again!\n");
			fflush(stdin);
		}
		else if (num < min || num > max){
			print_menu();
			printf("\nYour choice is not valid. Please try again!\n");
		}
		else not_valid = 0;
	}
	while (not_valid);

	system("cls");

	return num;
}

void play_game(){
	printf("Something went wrong :(\n");
	printf("Follow the comment for more information!\n");
	// Write your code here
}


void load_game(){
	printf("Something went wrong :(\n");
	printf("Follow the comment for more information!\n");
	// Write your code here
}


void show_top_player(){
	printf("Something went wrong :(\n");
	printf("Follow the comment for more information!\n");
	// Write your code here
}
