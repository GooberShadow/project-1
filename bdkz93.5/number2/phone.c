#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_fmt.c"
//Main
int main()
{
//Array for people to enter numbers
char str[15];
printf("Enter your 10 digit phone number:\n");
fgets(str, sizeof(str), stdin);
//calls PhoneCheck Function sending character array str
PhoneCheck(str);

return 0;
}


