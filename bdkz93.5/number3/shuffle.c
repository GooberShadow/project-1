#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//structure creation
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

//main
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
