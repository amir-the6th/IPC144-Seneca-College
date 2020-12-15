//==============================================
// Name:           Amirhossein Sabagh
// Student Number: 152956199
// Email:          asabagh@myseneca.ca
// Section:        NFF
// Date:           2020-07-25
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
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

	while (!done)
	{
		option = menu();
		printf("\n");
		switch (option)
		{
		case 1:
			printf("<<< Feature 1 is unavailable >>>\n");
			printf("\n");

			pause();
			printf("\n");
			break;
		case 2:
			printf("<<< Feature 2 is unavailable >>>\n");
			printf("\n");

			pause();
			printf("\n");
			break;
		case 3:
			printf("<<< Feature 3 is unavailable >>>\n");
			printf("\n");

			pause();
			printf("\n");
			break;
		case 4:
			printf("<<< Feature 4 is unavailable >>>\n");
			printf("\n");

			pause();
			printf("\n");
			break;
		case 5:
			printf("<<< Feature 5 is unavailable >>>\n");
			printf("\n");

			pause();
			printf("\n");
			break;
		case 6:
			printf("<<< Feature 6 is unavailable >>>\n");
			printf("\n");

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
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1) 
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
        }
		else if (isdigit(phoneNum) == 1)
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
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) 
{

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{

}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{

}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{

}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}