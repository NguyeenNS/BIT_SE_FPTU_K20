#include <stdio.h>
#include <stdlib.h>


void add_contact();
void edit_contact();
void delete_contact();
int make_choice();


int main(void)
{
	void (*funs[4])(void) = {NULL, &add_contact, &edit_contact, &delete_contact};
	int choice;

	do
	{
		choice = make_choice(0, 3);
		if (choice)
		{
			funs[choice]();
			printf("\nPress Enter to return to the menu.");
			getchar();
		}
	}
	while (choice);

	return 0;
}

void print_menu()
{
	system("cls"); // cls -> win ; clear -> mac, linux
	printf("CONTACT KEEPER\n");
	printf("------------------------\n");
	printf("1. Add new contact\n");
	printf("2. Edit contact\n");
	printf("3. Detele contact\n");
	printf("0. Exit\n");
}


int make_choice(int min, int max)
{
	int not_valid = 1, num, scanf_ret;
	char c;

	print_menu();
	fflush(stdin);
	do
	{
		printf("\nEnter your choice: ");
		scanf_ret = scanf("%d%c", &num, &c);
		if (scanf_ret < 2 || c != '\n')
		{
			print_menu();
			printf("\nYour choice is not valid. Please try again!\n");
			fflush(stdin);
		}
		else if (num < min || num > max)
		{
			print_menu();
			printf("\nYour choice is not valid. Please try again!\n");
		}
		else
		{
			not_valid = 0;
		}
	} while (not_valid);

	system("cls");

	return num;
}


void add_contact()
{
	printf("Write your code here to implement the add_contact() function.\n");
}


void edit_contact()
{
	printf("Write your code here to implement the edit_contact() function.\n");
}


void delete_contact()
{
	printf("Write your code here to implement the delete_contact() function.\n");
}

