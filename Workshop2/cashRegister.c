//==============================================
// Name:           Amirhossein Sabagh
// Student Number: 152956199
// Email:          asabagh@myseneca.ca
// Section:        NFF
// Workshop:       2 (in-lab)
//==============================================
// Start your code below:

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	double amount = 0.0 ;
	int cents, loonies;
	float owe;
	printf("Please enter the amount to be paid: $");
		scanf("%lf", &amount);

	cents = amount * 100;
	amount += 0.5;

	loonies = cents / 100;

	cents = cents % 100;

	owe = cents / 100.00;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, owe);

	loonies = cents / 25;
	cents = cents % 25;

    owe = cents / 100.00;
	printf("Quarters required: %d, balance owing $%.2lf\n", loonies, owe);

		return 0;
}

// dime = 10 cents
// nickle = 5 cents
// pennie = 1 cent
