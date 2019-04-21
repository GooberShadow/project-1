#include <stdio.h>

int odd ( int x )	//Tell me if x is odd
{
    return ( x & 1 );
}

int main()
{
    int num;
    printf ( "Please enter a number: " );
    scanf ( "%d", &num );

    printf ( "%d is %s\n", num, odd ( num ) ? "odd" : "even" );

    return ( 0 );
}
