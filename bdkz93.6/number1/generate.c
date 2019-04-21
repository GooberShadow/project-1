#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{


time_t t;
srand((unsigned) time(&t));

FILE* customerFile;
customerFile = fopen("./customers", "w+");


int i;
for(i=0; i< 1000; ++i)
{	
	fprintf(customerFile,
		"%d %d\n",
		5 * i + (rand() % 5 + 2), 
		rand() % 300 + 100);

}

fclose(customerFile);

return;
}
