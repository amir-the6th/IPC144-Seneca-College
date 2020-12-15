//==============================================
// Name:           Amirhossein Sabagh	
// Student Number: 152956199
// Email:          asabagh@myseneca.ca
// Section:        NFF
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 3

int main(void) {
	int i = 1;
	int high, low, totalTemp, totalHigh, totalLow;
	int totalTempReadings;

	high = low = totalTemp = totalHigh = totalLow = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");


	for (i = 1; i <= NUMS; i++) {
		printf("Enter the high value for day %d: ", i);
		scanf("%d", &high);
		printf("\n");

		printf("Enter the low value for day %d: ", i);
		scanf("%d", &low);
		printf("\n");

		if (high < -40 || high > 40 || low < -40 || low > 40 || high < low) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			i--;
			continue;
		}
		totalHigh += high;
		totalLow += low;
	}
	
	totalTemp = totalHigh + totalLow;

	// The max NUM of days is 4, the total temperature readings is doubled to include high and low temperature inputs

	totalTempReadings = NUMS * 2;

	printf("The average (mean) temperature was: %.2lf\n", (float) totalTemp / totalTempReadings);
	
	return 0;
}


/*
#include <stdio.h>

#define NUMS 3
#define MAXTEMP 40
#define MINTEMP -40


int main()
{
	int high = 0, low = 0; 
	int day;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (day = 1; day <= NUMS ; day++)
	{
		printf("Enter the high value for day %d: ", day);
			scanf("%d", &high[day]);
		printf("Enter the low value for day %d: ", day);
			scanf("%d", &low[day]);

			if (high[day] < -40 || high[day] > 40 || low[day] < -40 || low[day] > 40 || high[day] < low[day])
			{
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				day--;
				continue;
			}

			
	}



	return 0;
} */