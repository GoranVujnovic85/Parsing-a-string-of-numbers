/*
Author : Goran Vujnovic
Project Name : Parsing a string of numbers
Date created : 10/10/2023
Description :
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char string[]= "-1+1-3+3+1000";

	char *cursor = string;
	int sum = 0;
	int flag = 1;

	while(cursor != string + strlen(string))
	{
		int x = strtol(cursor, &cursor, 10);

		if(flag == 1)
		{
			sum += x;
		}
		else
		{
			sum -= x;
		}

		if(*cursor == '+')
		{
	     cursor++;
	     flag = 1;

		}
		else if(*cursor == '-')
		{
			cursor++;
			flag = -1;

		}
	}
	printf("Suma je: %d\n", sum);
	return 0;
}
