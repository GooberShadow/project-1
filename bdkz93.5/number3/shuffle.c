#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef enum suits { clubs, diamonds, hearty, spades} suit_t;
typedef struct
{
	unsigned int number  : 4;
	suit_t	     suit    : 2;
} card_t;


//functions
void PrintDeck(card_t* ptr);
void sort(card_t* ptr);
void shuffle(card_t* ptr);
int compare(const void* num, const void* x);

int main()
{

srand(time(NULL));

int i;

//initialize deck
card_t deck[52];
for(i = 0; i < 52; i++)
{
	deck[i].suit = (i/13)%4;
	deck[i].number = (i % 13);
}

printf("\nHere is the deck\n");
PrintDeck(deck);
printf("\nHere it is\n");
shuffle(deck);
printf("\nHERE IT IS SHUFFLED\n");
PrintDeck(deck);
sort(deck);
printf("\nHere it is sorted\n");
PrintDeck(deck);







return 0;
}

//print deck function
void PrintDeck(card_t* ptr)
{
	int i;
	for(i = 0; i < 52; ++i) 
	{
		printf("number is  %d\tSuit is %d\n", ptr[i].number, ptr[i].suit);
	}
	printf("\n\n");
	return;

}

//Shuffle
void shuffle(card_t* ptr)
{
	int i;
	int j;
	card_t temp;
	
	for(i = 0; i < 52; i++)
	{
		j = rand() % 52;
		temp = ptr[0];
		ptr[0] = ptr[j];
		ptr[j] = temp;
	}
	return;
}

//qsort
void sort(card_t* ptr)
{
	qsort(ptr, 52, sizeof(card_t), compare);
}
int compare(const void* num, const void* x)
{
	card_t* temp = (card_t*)num;
	card_t* temp2 = (card_t*)x;

	return(temp->number - temp2->number);
}


/*
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
}*/
