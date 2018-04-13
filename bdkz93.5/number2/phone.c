#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_fmt.c"
//DONE
//not using this function
/*void removeAll(char str[], char x);
*/
int main()
{

char str[15];
printf("Enter your 10 digit phone number:\n");
fgets(str, sizeof(str), stdin);
PhoneCheck(str);
/*
// - symbol
char *src, *dest;
src = dest = str;
while(*src != '\0')
{
	if (*src != '-')
	{
		*dest = *src;
		dest++;
	}
	src++;
}
*dest = '\0';

// () symbols right
src = dest = str;
while(*src != '\0')
{
	if (*src != ' ')
	{
		*dest = *src;
		dest++;
	}
	src++;
}
*dest = '\0';

printf("%s\n", str);


//White space
src = dest = str;
while(*src != '\0')
{
	if (*src != '(' )
	{
		*dest = *src;
		dest++;
	}
	src++;
}
*dest = '\0';

printf("%s\n", str);

// () symbols right
src = dest = str;
while(*src != '\0')
{
	if (*src != ' ')
	{
		*dest = *src;
		dest++;
	}
	src++;
}
*dest = '\0';

printf("%s\n", str);


// ( ) symbols left
src = dest = str;
while(*src != '\0')
{
	if (*src != ')' )
	{
		*dest = *src;
		dest++;
	}
	src++;
}
*dest = '\0';

printf("%s\n", str);

// () symbols right
src = dest = str;
while(*src != '\0')
{
	if (*src != ' ')
	{
		*dest = *src;
		dest++;
	}
	src++;
}
*dest = '\0';

printf("%s\n", str);



char insert = '-';
char temp;
char temp2;
char temp3;
char temp4;

temp = str[6];
temp2 = str[7];
temp3 = str[8];
temp4 = str[9];

str[7] = temp;
str[8] = temp2;
str[9] = temp3;
str[10] = temp4;
str[6] = insert;

	printf("(%.3s) %s\n",str, &(str[strlen (str) - 8])); 
*/
return 0;
}

/*void removeAll(char str[], char x)
{
	int i, j;
	for(i=0; str[i] != 0; ++i)
	{
		while(str[i]==x)
		{
			j=i;
			while(str[j]!=0)
			{
				str[j]=str[j+i];
				++j;
			}
			x--;
		}
	}
}*/

