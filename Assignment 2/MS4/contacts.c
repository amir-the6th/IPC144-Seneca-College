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

#include "contacts.h"
#include "contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{
    char option;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else {
        strcpy(&name->middleInitial[0], "\0");
    }                                                                         // ADD AN ELSE STATEMENT IN HERE TO EMPTY THE ARRAY IF THE USER SAYS NO 

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
    char option;

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();

    while (address->streetNumber < 0) {

        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    option = yes();

    if (option == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();

        while (address->apartmentNumber < 0) {

            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    else {
        address->apartmentNumber = 0;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* phoneNum)
{
    char option;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(phoneNum->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(phoneNum->home);
    }
    else {
        strcpy(&phoneNum->home[0], "\0");
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    option = yes();

    if (option == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(phoneNum->business);
    }
    else {
        strcpy(&phoneNum->business[0], "\0");
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
    