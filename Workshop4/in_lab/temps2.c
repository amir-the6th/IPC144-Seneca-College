//==============================================
// Name:           Amirhossein Sabagh	
// Student Number: 152956199
// Email:          asabagh@myseneca.ca
// Section:        NFF
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int tempDay, days = 0;
	int Htemp, Ltemp;
		int	HighTemp[SIZE] = { 0 };
		int	LowTemp[SIZE] = { 0 };

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while ((days < 3) || (days > 10))
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}

	for (tempDay = 1; tempDay <= days; tempDay++)
	{
		printf("Day %d - High: ", tempDay);
		scanf("%d", &Htemp);

		printf("Day %d - Low: ", tempDay);
		scanf("%d", &Ltemp);

		HighTemp[tempDay - 1] = Htemp;
		LowTemp[tempDay - 1] = Ltemp;
	}

	printf("\n");
	printf("Day  Hi  Low\n");


	for (tempDay = 0; tempDay <= days - 1; tempDay++)
	{
		printf("%d    %d    %d\n", (tempDay + 1), HighTemp[tempDay], LowTemp[tempDay]);
	}


	return 0;
}