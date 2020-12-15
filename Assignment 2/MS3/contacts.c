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

#include <stdio.h>

#include "contacts.h"

#include "contactHelpers.h"

// +-----------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2     |
// |        function definitions below...                |
// |                                                     |
// | HINT:  Update the getNumbers function to use the    |
// |        new helper function "getTenDigitPhone"       |
// |        where applicable                             |
// +-----------------------------------------------------+

// getName:
void getName(struct Name* name)
{
    char option;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
        clearKeyboard();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
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
    scanf("%40[^\n]%*c", address->street);

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

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
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

    printf("Do you want to enter a business phone number? (y or n): ");
    option = yes();

    if (option == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(phoneNum->business);
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
    getNumbers(&contact->phoneNum);
}

