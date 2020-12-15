//==============================================
// Name:           Amirhossein Sabagh
// Student Number: 152956199
// Email:          asabagh@myseneca.ca
// Section:        NFF
// Workshop:       2 (in-lab)
//==============================================
// Paste your in-lab code below and upgrade it to the at-home specifications



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	double amount = 0.0;
	int cents, loonies;
	float owe;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	
	float GST = amount * .13 + .005;
	printf("GST: %1.2f\n", GST);

	float totalDue = GST + amount;
	printf("Balance owing: $%.2f\n", totalDue);


	cents = totalDue * 100;
	totalDue += 0.5;

	loonies = cents / 100;
	cents = cents % 100;
	owe = cents / 100.00;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, owe);

	loonies = cents / 25;
	cents = cents % 25;
	owe = cents / 100.00;
	printf("Quarters required: %d, balance owing $%.2lf\n", loonies, owe);


	loonies = cents / 10;
	cents = cents % 10;
	owe = cents / 100.00;
	printf("Dimes required: %d, balance owing $%.2lf\n", loonies, owe);


	loonies = cents / 5;
	cents = cents % 5;
	owe = cents / 100.00;
	printf("Nickels required: %d, balance owing $%.2lf\n", loonies, owe);


	loonies = cents / 1;
	cents = cents % 1;
	owe = cents / 100.00;
	printf("Pennies required: %d, balance owing $%.2lf\n", loonies, owe);


	return 0;
}