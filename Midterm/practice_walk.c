/*#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define SZ 3

int main(void)
{
	int key[SZ] = { 234, 567, 948 };
	int value[SZ] = { 0 };
	int i;

	for ( i = 0; i < SZ; i++)
	{
		printf("Please enter a value for key %d: ", key[i]);//user enters 7, then 6, then 9
		scanf("%d", &value[i]);
	}
	printf("\n\n");

	for ( i = 0; i < SZ; i++)
	{
		if (value[i] % 2)
		{
			value[i]++;
		}
		printf("The value of key: %d is %d\n", key[i], value[i]);
	}

	return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS

 #define NUM_STUDENTS 2
 #define NUM_DIGITS 2
#include <stdio.h>
 struct StudentInfo
 {
    int studentId;
    double mark;
 };

 int main(void)
 {
     struct StudentInfo students[NUM_STUDENTS] =
    {
        {33, 68.4},
        {54, 72.8}
    };
    int i, j, k, n, flag, div, digit;

    for (i = 0; i < NUM_STUDENTS; i++)
    {
        flag = 1;
        n = students[i].studentId;
        for (j = NUM_DIGITS - 1; j >= 0; j--)
        {
            div = 1;
            for (k = 0; k < j; k++)
            {
               div *= 10;
            }
            digit = n / div;
            n = n % div;
            if (0 != (digit % 2)) flag = 0;
        }
        if (flag)
        {
            printf("%d %.2lf\n", students[i].studentId, students[i].mark);
        }
    }

    return 0;
