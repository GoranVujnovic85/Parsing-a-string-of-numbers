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
	char string[]= "200 22, 111";

	char *cursor = string;
	int sum = 0;

    /* Petlja ce se izvrsavati dok cursor ne dostigne kraj niz
	   String + strlen(string); ova kombinacija oznacava kraj niza  */
	while(cursor != string + strlen(string))
	{
		/* strtol funkcija pretvara znakovni niz u brojeve, argument 10 oznacava,
		   da se radi o decimalnim brojevima, cursor je znakovni niz koji zelim pretvoriti,
		   dok &cursor nam govori gde je kraj naseg znakovnog pretvaranja */
		int x = strtol(cursor, &cursor, 10);

		while(*cursor == ' ' || *cursor == ',')
		{
			cursor++;
		}
		sum += x;

	}
	printf("Suma je: %d\n", sum);
	return 0;
}
