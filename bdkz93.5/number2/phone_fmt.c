//Function for phone

void PhoneCheck(char str[])
{
// - Symbol
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
/*
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
*/

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
}
