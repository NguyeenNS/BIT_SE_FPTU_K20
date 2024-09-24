#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	printf("=========\n");
	printf("CARO GAME\n");
	printf("=========\n");
	printf("1. Play game\n");
	printf("2. Load game\n");
	printf("3. Show top player\n");
	printf("4. User's Guide\n");
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

	/*
		size: Kich thuoc ban co se la size(W) x size(H)
		blank_count: Dem so cho trong tren ban co, quyet dinh gia tri cua "cont"
		vld_turn: Kiem tra nuoc di co hop le hay khong
		vld: Kiem tra luot di co hop le hay khong, bo tro chuc nang cho "vld_turn"
		xwin, owin: true = thang, false = thua, 2false = hoa
		posX, posY: Toa do tren ban co, posX tuong ung voi cot, posY tuong ung voi hang
		xcheck, ocheck: Kiem tra so quan co lien tuc cung loai tren moi hang cot hoac duong cheo
		xcount, ocount: Bien phu luu gia tri cua xcheck va ocheck
	*/

	int luot = 0, posX, posY, size, xcheck, ocheck, xcount, ocount;
	char quit;
	bool cont = true,
		 vld_turn = true,
		 xwin = false,
		 owin = false,
		 vld = false;
	printf("Board size: ");
	scanf("%d", &size);

	char map[size][size];
	int blank_count = size * size;

	// Bat dau tao ban co
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			map[i][j] = '-';
		}
	}
	// Ket thuc tao ban co

	/*
		Tao luot di lan luot cho hai nguoi choi luan phien bang cach tang giam bien "luot"
		0 tuong ung voi luot cua X, 1 tuong ung voi luot cua O
		2 la luot check sau X, 3 la luot check sau O
		Thu tu vong lap bien "luot"
		0 -> 2 -> 1 -> 3
	*/

	// Bat dau luot choi
	while (cont == true) {
		system("cls");

		if (cont == true){ // Kiem tra xem tran dau co the tiep tuc khong

			do { // Tao luot choi cho hai nguoi choi

				// Bat dau luot X danh
				if (luot == 0 && cont == true){ // cont == true cho phep tro choi tiep tuc

					system("cls");

				    do {
						system("cls");

						// Bat dau in ban co luot X
						for (int i = 0; i < size; i++){
						if (i < 9){
							printf("%d   ", i + 1);
						}
						else printf("%d  ", i + 1);
						}

						printf("\n\n");
						for (int i = 0; i < size; i++){
							for (int j = 0; j < size; j++){
								printf("%c   ", map[i][j]);
								if (j + 1 == size){
									printf("%d", i + 1);
									printf("\n\n");
								}
							}
						}
						printf("\n");
						// Ket thuc in ban co luot X

						// Bat dau luot X nhap vi tri muon danh
						vld = false;
						if (vld_turn == false){
							printf("Your choice is not valid. Please try again!\n");
						}
						printf("Den luot X: ");
						scanf("%d%d", &posX, &posY);
						if (map[posY - 1][posX - 1] == '-'){
							map[posY - 1][posX - 1] = 'X';
							vld = true;
							vld_turn = true;
							blank_count--;
						}
						else {
							vld_turn = false;
						}

						// Bat dau kiem tra xem co con cho danh khong
						if (blank_count == 0){
							cont = false;
						}
						// Ket thuc kiem tra xem co con cho danh khong

				    }
					while (vld == false && cont == true); // cont == true cho phep tro choi tiep tuc
					luot = 2;
					// Ket thuc luot X chon vi tri muon danh
				}
				// Ket thuc luot X danh


				// Bat dau luot O danh
				if (luot == 1 && cont == true){ // cont == true cho phep tro choi tiep tuc

					system("cls");

					do {

						system("cls");

						// Bat dau in ban co luot O
						for (int i = 0; i < size; i++){
							if (i < 9){
								printf("%d   ", i + 1);
							}
							else printf("%d  ", i + 1);
						}

						printf("\n\n");
						for (int i = 0; i < size; i++){
							for (int j = 0; j < size; j++){
								printf("%c   ", map[i][j]);
								if (j + 1 == size){
									printf("%d", i + 1);
									printf("\n\n");
								}
							}
						}
						printf("\n");
						// Ket thuc in ban co luot O

						// Bat dau luot O chon vi tri muon danh
						vld = false;
						if (vld_turn == false && cont == true){
							printf("Your choice is not valid. Please try again!\n");
						}
						printf("Den luot O: ");
						scanf("%d%d", &posX, &posY);
						if (map[posY - 1][posX - 1] == '-'){
							map[posY - 1][posX - 1] = 'O';
							vld = true;
							vld_turn = true;
							blank_count--; // Giam so o trong di 1 don vi
						}
						else {
							vld_turn = false;
						}

						// Bat dau kiem tra xem co con cho danh khong
						if (blank_count == 0){
							cont = false;
						}
						// Ket thuc kiem tra xem co con cho danh khong

				    }
					while (vld == false && cont == true); // cont == true cho phep tro choi tiep tuc
					luot = 3;
					// Ket thuc luot O chon vi tri muon danh
				}
				// Ket thuc luot O danh


				// Bat dau check sau luot X
					if (luot == 2 && cont == true){
						xcheck = 0;
						xcount = 0;
						for (int i = 0; i < size; i++){
							for (int j = 0; j < size; j++){
								if (map[i][j] == 'X'){
									xcheck++;
									xcount++;
									while (xcheck != 0 && cont == true){ // tao bon luot check lan luot theo 2 duong cheo va 2 duong thang

										// Bat dau check theo duong cheo y = x
										while (map[i + xcount][j + xcount] == 'X' && cont == true){
											xcheck++;
											xcount++;


											// Bat dau doi huong check
											if (map[i + xcount][j + xcount] != 'X'){
												xcount = 1;
												while (map[i - xcount][j - xcount] == 'X' && cont == true){
													xcheck++;
													xcount++;
													if (xcheck > 4){
													    xwin = true;
													    cont = false;
														xcount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (xcheck > 4 && cont == true){
												xwin = true;
												cont = false;
												xcount = 0;
												break;
											}
											else {
												xcount = 1;
												xcheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo y = x

									    // Bat dau check theo duong cheo y = -x
										while (map[i + xcount][j - xcount] == 'X' && cont == true){
											xcheck++;
											xcount++;


											// Bat dau doi huong check
											if (map[i + xcount][j - xcount] != 'X' && cont == true){
												xcount = 1;
												while (map[i - xcount][j + xcount] == 'X' && cont == true){
													xcheck++;
													xcount++;
													if (xcheck > 4){
													    xwin = true;
													    cont = false;
													    xcount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (xcheck > 4){
												xwin = true;
												cont = false;
												xcount = 0;
												break;
											}
											else {
												xcount = 1;
												xcheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo y = -x

										// Bat dau check theo duong cheo y = 0
										while (map[i + xcount][j] == 'X' && xcount != 0){
											xcheck++;
											xcount++;


											// Bat dau doi huong check
											if (map[i + xcount][j] != 'X'){
												xcount = 1;
												while (map[i - xcount][j] == 'X'){
													xcheck++;
													xcount++;
													if (xcheck > 4){
													    xwin = true;
													    cont = false;
													    xcount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (xcheck > 4){
												xwin = true;
												cont = false;
												xcount = 0;
												break;
											}
											else {
												xcount = 1;
												xcheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo y = 0


									    // Bat dau check theo duong cheo x = 0
										while (map[i][j + xcount] == 'X' && xcount != 0){
											xcheck++;
											xcount++;


											// Bat dau doi huong check
											if (map[i][j + xcount] != 'X'){
												xcount = 1;
												while (map[i][j - xcount] == 'X'){
													xcheck++;
													xcount++;
													if (xcheck > 4){
													    xwin = true;
													    cont = false;
													    xcount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (xcheck > 4){
												xwin = true;
												cont = false;
												xcount = 0;
												break;
											}
											else {
												xcount = 1;
												xcheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo x = 0

										xcount = 0;
										xcheck = 0; // Reset bo dem
									}
								}
							}
						}
						luot = 1;
						// Den luot O danh
					}
				// Ket thuc check sau luot X

				// Bat dau check sau luot O
					if (luot == 3 && cont == true){
						ocheck = 0;
						ocount = 0;
						for (int i = 0; i < size; i++){
							for (int j = 0; j < size; j++){
								if (map[i][j] == 'O'){
									ocheck++;
									ocount++;
									while (ocheck != 0){ // tao bon luot check lan luot theo 2 duong cheo va 2 duong thang

										// Bat dau check theo duong cheo y = x
										while (map[i + ocount][j + ocount] == 'O' && ocount != 0){
											ocheck++;
											ocount++;


											// Bat dau doi huong check
											if (map[i + ocount][j + ocount] != 'O'){
												ocount = 1;
												while (map[i - ocount][j - ocount] == 'O'){
													ocheck++;
													ocount++;
													if (ocheck > 4){
													    owin = true;
													    cont = false;
													    ocount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (ocheck > 4){
												owin = true;
												cont = false;
												ocount = 0;
												break;
											}
											else {
												ocount = 1;
												ocheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo y = x

									    // Bat dau check theo duong cheo y = -x
										while (map[i + ocount][j - ocount] == 'O' && ocount != 0){
											ocheck++;
											ocount++;


											// Bat dau doi huong check
											if (map[i + ocount][j - ocount] != 'O'){
												ocount = 1;
												while (map[i - ocount][j + ocount] == 'O'){
													ocheck++;
													ocount++;
													if (ocheck > 4){
													    owin = true;
													    cont = false;
													    ocount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (ocheck > 4){
												owin = true;
												cont = false;
												ocount = 0;
												break;
											}
											else {
												ocount = 1;
												ocheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo y = -x

										// Bat dau check theo duong cheo y = 0
										while (map[i + ocount][j] == 'O' && ocount != 0){
											ocheck++;
											ocount++;


											// Bat dau doi huong check
											if (map[i + ocount][j] != 'O'){
												ocount = 1;
												while (map[i - ocount][j] == 'O'){
													ocheck++;
													ocount++;
													if (ocheck > 4){
													    owin = true;
													    cont = false;
													    ocount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (ocheck > 4){
												owin = true;
												cont = false;
												ocount = 0;
												break;
											}
											else {
												ocount = 1;
												ocheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo y = 0


									    // Bat dau check theo duong cheo x = 0
										while (map[i][j + ocount] == 'O' && ocount != 0){
											ocheck++;
											ocount++;


											// Bat dau doi huong check
											if (map[i][j + ocount] != 'O'){
												ocount = 1;
												while (map[i][j - ocount] == 'O'){
													ocheck++;
													ocount++;
													if (ocheck > 4){
													    owin = true;
													    cont = false;
													    ocount = 0;
														break;
													}
												}
											}
											// Ket thuc doi huong check

											if (ocheck > 4){
												owin = true;
												cont = false;
												ocount = 0;
												break;
											}
											else {
												ocount = 1;
												ocheck = 1;
												break;
											}
										}
									    // Ket thuc check theo duong cheo x = 0

										ocount = 0; // Reset bo dem
										ocheck = 0;
									}
								}
							}
						}
						luot = 0;
						// Den luot X danh
					}
				// Ket thuc check sau luot O

			} while (cont == true); // cont == true cho phep tro choi tiep tuc
		}
	}
	// Ket thuc luot choi

	// Bat dau hien thi ket qua
	while (1) {
		system("cls");

		// Bat dau in ban co hien thi ket qua
		for (int i = 0; i < size; i++){
			if (i < 9){
				printf("%d   ", i + 1);
			}
			else printf("%d  ", i + 1);
		}
		printf("\n\n");
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				printf("%c   ", map[i][j]);
				if (j + 1 == size){
					printf("%d", i + 1);
					printf("\n\n");
				}
			}
		}
		// Ket thuc in ban co hien thi ket qua

		// Bat dau kiem tra thang / thua / hoa
		if (xwin == true){
			printf("\nX thang\n");
		}
		if (owin == true){
			printf("\nO thang\n");
		}
		if (xwin == false && owin == false){
			printf("\nHoa co\n");
		}
		scanf("%c", &quit);
		if (quit == '\n'){
			break;
		}
		// Ket thuc kiem tra thang / thua / hoa

	}
	// Ket thuc hien thi ket qua
}


void load_game(){
	printf("Code here");
}


void show_top_player(){
	printf("Code here");
}


