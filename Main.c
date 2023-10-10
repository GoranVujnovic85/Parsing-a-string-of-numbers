/*
Author : Goran Vujnovic
Project Name : Parsing a string of numbers
Date created : 10/10/2023
Description :
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	char string[]= "-1+1-3+3+1000+100000000000000000000000000";

	char *cursor = string;
	int sum = 0;
	int flag = 1;

	while(cursor != string + strlen(string))
	{
		int x = strtol(cursor, &cursor, 10);

		/* ERRNO se koristi za detekciju gresaka, ako se postavi na ERANGE,
		 zanci da izlazi van domasaja u nasem slucaju int. Dolazi do underflow ili overflow.
		 Cesto se koristi kod funkcija atoi, strtol */
		if(errno == ERANGE)
		{
			printf("Number is too big for store!\n");

		}
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
