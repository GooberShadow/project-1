#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
void printBitVector(unsigned char bitVec[], int size);

int main()
{
	const int size = ceil(52 / (sizeof(unsigned int) * 8));
	unsigned char bitVector[size];
	card_t deck[52];

	srand(time(NULL));
//initialize bit vector
char* ptr;
int count = 0;
for(ptr = bitVector; count < size + 1; ptr++)
{
	memset(ptr, 0, sizeof(unsigned char));
	count++;
}

//Randomize the deck
int i = 0;
int j;
int pos;
unsigned char flag;


while(i < 52)
{
	flag = 1;
	j = rand() % 52;
	flag = flag << (j % (sizeof(unsigned char) * 8));
	pos = j / (sizeof(unsigned char) * 8);

	while(bitVector[pos] & flag)
	{
		flag = 1;
		j = rand() % 52;
		flag = flag << (j % (sizeof(unsigned char) * 8));
		pos = j / (sizeof(unsigned char) * 8);
	} 

	bitVector[pos] |= flag;

	deck[j].number = i % 13;
	deck[j].suit = (i / 13) % 4;

	i++;

}

//Print unsorted
printf("\nUnsorted Deck:\n");
PrintDeck(deck);


sort(deck);
printf("\nSorted Deck By Suit\n");
PrintDeck(deck);

return 0;
}
//print the vector
void printBitVector(unsigned char bitVec[], int size)
{
	int i;
	int j;
	unsigned char flag;
	for(i = size; i >= 0; --i)
	{
		for(j = sizeof(unsigned char) * 8 - 1; j >= 0; --j)
		{
			flag = 1;
			flag = flag << j;
			
			if(bitVec[i] & flag)
			{	printf("1");}
			else
			{	printf("0");}
			if(j == 0)
			{	printf("\tbitVector[%d]\n", i);}
		}
	}


	return;

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

	return(temp->suit - temp2->suit);
}
