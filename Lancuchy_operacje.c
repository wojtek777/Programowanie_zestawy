#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void reverse_and_upper (char* lanc, int dlugosc)
{
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		int c = *(lanc + i);
		putchar (toupper(c));
	}
}

void number_to_word (unsigned int number)
{
	int number_of_words = 0;
	int un_nt;
	int i = 20;
	char** words = (char**) malloc (i * sizeof (char*));
	

	while (number > 0)
	{
		un_nt = number % 10;
		if (un_nt == 0)
		{
			*(words + number_of_words) = (char*) malloc (6 * sizeof (char));
			strcpy (*(words + number_of_words), "zero ");
		}
		else if (un_nt == 1)
		{
			*(words + number_of_words) = (char*) malloc (7 * sizeof (char));
			strcpy (*(words + number_of_words), "jeden ");
		}
		else if (un_nt == 2)
		{
			*(words + number_of_words) = (char*) malloc (5 * sizeof (char));
			strcpy (*(words + number_of_words), "dwa ");
		}
		else if (un_nt == 3)
		{
			*(words + number_of_words) = (char*) malloc (6 * sizeof (char));
			strcpy (*(words + number_of_words), "trzy ");
		}
		else if (un_nt == 4)
		{
			*(words + number_of_words) = (char*) malloc (8 * sizeof (char));
			strcpy (*(words + number_of_words), "cztery ");
		}
		else if (un_nt == 5)
		{
			*(words + number_of_words) = (char*) malloc (6 * sizeof (char));
			strcpy (*(words + number_of_words), "piec ");
		}
		else if (un_nt == 6)
		{
			*(words + number_of_words) = (char*) malloc (7 * sizeof (char));
			strcpy (*(words + number_of_words), "szesc ");
		}
		else if (un_nt == 7)
		{
			*(words + number_of_words) = (char*) malloc (8 * sizeof (char));
			strcpy (*(words + number_of_words), "siedem ");
		}
		else if (un_nt == 8)
		{
			*(words + number_of_words) = (char*) malloc (7 * sizeof (char));
			strcpy (*(words + number_of_words), "osiem ");
		}
		else if (un_nt == 9)
		{
			*(words + number_of_words) = (char*) malloc (10 * sizeof (char));
			strcpy (*(words + number_of_words), "dziewiec ");
		}
		else
		{
			exit(1);
		}
		number = number - (number % 10);
		if (number >= 10) 
			number /= 10;
		number_of_words++;
	}
	for (int j = number_of_words; j >= 0; j--)
	{
		printf ("%s ", *(words + number_of_words));
		free (*(words + number_of_words));
	}	
	printf("\n");
	free (words);
}

int main()
{
	char wejscie[100];
	scanf("%s", wejscie);
	int number_to_converse;
	scanf("%d", &number_to_converse);
	reverse_and_upper(wejscie, strlen(wejscie));
	number_to_word (number_to_converse);
	
	return 0; 
}
