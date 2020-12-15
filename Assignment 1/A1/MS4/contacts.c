/* -------------------------------------------
Name:   Amirhossein Sabagh
Student number: 152956199
Email:  asabagh@myseneca.ca
Section:    NFF
Date:       2020-07-05
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"


void Clear() {
    while (getchar() != '\n');
}


void getName(struct Name *name) {

    char yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    Clear();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf(" %c", &yesNo);
    Clear();

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        Clear();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    Clear();
    
}

void getAddress(struct Address *address)
{
    char yesNo;

    do {
        printf("Please enter the contact's street number: ");
        scanf("%d", &address->streetNumber);
        Clear();
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    Clear();

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c", &yesNo);
    Clear();

    if (yesNo == 'y' || yesNo == 'Y') {
        do {
            printf("Please enter the contact's apartment number: ");
            scanf("%d", &address->apartmentNumber);
            Clear();
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode);
    Clear();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    Clear();
}

void getNumbers(struct Numbers *numbers)
{
    char yesNo;

    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c", &yesNo);
    Clear();

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]", numbers->cell);
        Clear();
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &yesNo);
    Clear();

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);
        Clear();
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &yesNo);
    Clear();

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);
        Clear();
    }
}