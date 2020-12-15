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
	int highestTemp = -100, highestTempDay, lowestTemp = +100, lowestTempDay;
	//int totalHigh = 0, totalLow = 0, totalTemp = 0;
	int avgDay = 0;
	double	Sum = 0;



	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	if ((days < 3) || (days > 10)) {
		printf("Please enter the number of days, between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");

		while ((days < 3) || (days > 10))
		{
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &days);
			printf("\n");
		}
	}

	for (tempDay = 1; tempDay <= days; tempDay++)
	{
		// prompt the user to insert temps
		printf("Day %d - High: ", tempDay);
		scanf("%d", &Htemp);

		printf("Day %d - Low: ", tempDay);
		scanf("%d", &Ltemp);

		// save temps in the array
		HighTemp[tempDay - 1] = Htemp;
		LowTemp[tempDay - 1] = Ltemp;

		/* // calculate the total temp
		totalHigh += Htemp;
		totalLow += Ltemp; */

		/*// highest and lowest temp, which day
			if (Htemp > highestTemp)
			{
			highestTemp = Htemp;
			highestTempDay = tempDay;
			}

			if (Ltemp < lowestTemp)
			{
			lowestTemp = Ltemp;
			lowestTempDay = tempDay;
			}
		*/
	}

	// show the table of days and temps
		printf("\n");
		printf("Day  Hi  Low\n");
	for (tempDay = 0; tempDay <= days - 1; tempDay++)
	{
		printf("%d    %d    %d\n", (tempDay + 1), HighTemp[tempDay], LowTemp[tempDay]);
	}

	// calculate highest and lowest temp, which day
	for (tempDay = 0; tempDay <= days - 1; tempDay++)
	{
		if (HighTemp[tempDay] > highestTemp) {
			highestTemp = HighTemp[tempDay];
			highestTempDay = tempDay + 1;
		}
		if (LowTemp[tempDay] < lowestTemp) {
			lowestTemp = LowTemp[tempDay];
			lowestTempDay = tempDay + 1;
		}
	}

	//print the highest and lowest temps
		printf("\n");
		printf("The highest temperature was %d, on day %d\n", highestTemp, highestTempDay);
		printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestTempDay);
		printf("\n");

		do
		{
			printf("Enter a number between 1 and %d to see the average temperature for"
					" the entered number of days, enter a negative number to exit: ", days);
			scanf("%d", &avgDay);
			printf("\n");

			while ((avgDay > days) || (avgDay == 0))
			{
                
				printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
				scanf("%d", &avgDay);
				printf("\n");
			}

			if (avgDay > 0 )
			{
				for (tempDay = 0; tempDay <= avgDay - 1; tempDay++)
				{
					Sum = Sum + HighTemp[tempDay] + LowTemp[tempDay];
				}
				double Average = (Sum / (avgDay * 2));
				printf("The average temperature up to day %d is: %.2f\n", avgDay, Average);
				printf("\n");
				Sum = 0;
			}

		}

		while (avgDay >= 0);

		printf("Goodbye!\n");


		return 0;
}




	/* do  enter number between 1 to 5 (negative to exit) -> scanf
		while number is not in that range, say invalid input
			if input was negative, say goodbye
		*/

	/*
	Display the highest temperature, and the day on which it occurred
	Display the lowest temperature, and the day on which it occurred
	Calculate and display the mean (average) temperature for a period entered by the user, until the user enters -1.
	*/

