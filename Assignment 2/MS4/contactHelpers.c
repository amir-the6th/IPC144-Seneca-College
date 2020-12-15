//==============================================
// Name:           Amirhossein Sabagh
// Student Number: 152956199
// Email:          asabagh@myseneca.ca
// Section:        NFF
// Date:           2020-07-27 
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contactHelpers.h"
#include "contacts.h"

#define MAXCONTACTS 5

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+	

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	int value = 0;
	char newLine = 'x';

	scanf("%d%c", &value, &newLine);

	while (newLine != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &newLine);
	}

	return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int value;

	// call another function and use its returned value
	value = getInt();

	while (min > value || max < value)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		value = getInt();
	}

	return value;
}

// yes function definition goes here:
int yes(void)
{
	char yn = 'x';
	char newline = 'x';

	scanf(" %c%c", &yn, &newline);
	while ((yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') || newline != '\n') {
		if (newline != '\n') {
			clearKeyboard();
		}
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &yn, &newline);
	}
	return (yn == 'y' || yn == 'Y');
}


// menu function definition goes here:
int menu(void)
{
	int option = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	option = getIntInRange(0, 6);
	/*
	scanf("%d", &option);

	while (option < 0 || option > 6)
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Select an option:> ");
		scanf("%d", &option);
	}
	*/
	return option;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{	
	int option;
	int done = 0;

	struct Contact TWDcontacts[MAXCONTACTS] = { { {"Rick", {'\0'}, "Grimes"},
								   {11, "Trailer Park", 0, "A7A 2J2", "King City"},
								   {"4161112222", "4162223333", "4163334444"}},
							   {
								   {"Maggie", "R.", "Greene"},
								   {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
								   {"9051112222", "9052223333", "9053334444"} },
								{
									{"Morgan", "A.", "Jones"},
									{77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
									{"7051112222", "7052223333", "7053334444"} },
								{
									{"Sasha", {'\0'}, "Williams"},
									{55, "Hightop House", 0, "A9A 3K3", "Bolton"},
									{"9052223333", "9052223333", "9054445555"} },
	};


	while (!done)
	{
		option = menu();
		printf("\n");
		switch (option)
		{
		case 1:
			displayContacts(TWDcontacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(TWDcontacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(TWDcontacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(TWDcontacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(TWDcontacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(TWDcontacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		default:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)
			{
				printf("\nContact Management System: terminated");
				done = 1;
			}
			printf("\n");
		}
	}
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------

void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i = 0, number = 0;

	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		number = 0;
		// (String Length Function: validate entry of 10 characters)
		for (i = 0; phoneNum[i] != '\0'; i++) {
			if (isdigit(phoneNum[i]) != 0)
				number++;
		}

		if (strlen(phoneNum) == 10 && number == 10)
		{
			needInput = 0;
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;
	int Return = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			Return = i;
		}
	}
	return Return;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}


// displayContact:
void displayContact(const struct Contact* contact)
{
	// Line 1
	printf(" %s ", contact->name.firstName);
	if (strlen(contact->name.middleInitial) == 0) {
	}
	else {
		printf("%s ", contact->name.middleInitial);
	}
	printf("%s\n", contact->name.lastName);
	
	// Line 2
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	
	// Line 3
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int count = 0;

	displayContactHeader();
	
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}
	
	//valid -= invalid;
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char phoneNumtwo[11];
	int indexFound;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNumtwo);
	indexFound = findContactIndex(contacts, size, phoneNumtwo);
	if (indexFound == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		printf("\n");
		displayContact(&contacts[indexFound]);
		printf("\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int add = -1;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)	add = i;
	}
	
	if (add != -1)
	{
		getContact(&contacts[add]);
		printf("--- New contact added! ---\n\n");
	}
	else {
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
}


// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char phoneNumtwo[11];
	int indexFound;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNumtwo);
	indexFound = findContactIndex(contacts, size, phoneNumtwo);

	if (indexFound != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[indexFound]);
		printf("\n");
		
		printf("Do you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&contacts[indexFound].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&contacts[indexFound].address);
		}


		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&contacts[indexFound].numbers);
		}

		printf("--- Contact Updated! ---\n\n");
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char phoneNumtwo[11];
	int indexFound;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNumtwo);
	indexFound = findContactIndex(contacts, size, phoneNumtwo);

	if (indexFound != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[indexFound]);
		printf("\n");
		
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes())
		{
			strcpy(&contacts[indexFound].numbers.cell[0], "\0");
			printf("--- Contact deleted! ---\n");
			printf("\n");
		}
		else {	printf("\n");	}
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	struct Contact tempSort;

	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0) {
				if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) < 0) {
					tempSort = contacts[i];
					contacts[i] = contacts[j];
					contacts[j] = tempSort;
				}
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
	printf("\n");
}
