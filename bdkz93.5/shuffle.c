#include <stdio.h>
#include <string.h>

int main()
{
//enum suits { clubs, diamonds, hearts, spades};
//enum faces { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

char * suits_str[4] = {"spades", "hearts", "diamonds", "clubs"};
char * faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

int suit = 0;
int face = 12;
int i;
int j;


//sort the deck
int deck[52];
for (i = 0; i < 52; i++)
{
	deck[i] = i;
}

//randomize the deck
for (i = 0; i < 1000; i++)
{
	int from = rand() % 52;
	int to = rand() % 52;
	int card = deck[from];
	deck[from] = deck[to];
	deck[to] = card;
}

//print the deck
printf("Here is a shuffled deck:\n");
for (i = 0; i < 52; i++)
{
	int card = deck[i];
	int suit = card / 13;
	int face = card % 13;
	printf("%s of %s\n", suits_str[suit], faces_str[face]);
}


//sorting the deck
for (i = 0; i < 52; i++)
{
	deck[i] = i;
}

//print the deck
printf("\nSORTED IT HERE YA GO!!!\n");

//sorting it by number
for ( i = 0; i < 13; i++)
{
	for ( j = 0; j < 4; j++)
	{
		printf("%s of %s\n", suits_str[j], faces_str[i]);
	}
}


return 0;
}
