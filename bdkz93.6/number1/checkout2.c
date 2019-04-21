#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct Customer
{
	float arrivalTime;
	float serviceTime;
} Customer_t;

typedef struct Queue
{
	int front, rear;
	unsigned int size, capacity;
	Customer_t* customerArray;
} Queue_t;

Customer_t* createCustomer(float TimeofA, float TimeofS)
{
	Customer_t* cust = (Customer_t*) malloc(sizeof(Customer_t));
	cust->arrivalTime = TimeofA;
	cust->serviceTime = TimeofS;
	return cust;
}

Queue_t* createQueue(unsigned int capacity)
{
	Queue_t* queue = (Queue_t*) malloc(sizeof(Queue_t));
	queue->capacity = capacity;
	queue->size = 0;
	queue->front = 0;
	queue->rear = capacity - 1;
	queue->customerArray = (Customer_t*) malloc(queue->capacity * sizeof(Customer_t*));
	return queue;
}

int isFull(Queue_t* queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(Queue_t* queue)
{
	return (queue->size == 0);
}

Customer_t* front(Queue_t* queue)
{
	if(isEmpty(queue))
	{
		return NULL;
	}
	Customer_t* cust = &queue->customerArray[queue->front];
	return cust;
}

Customer_t* rear(Queue_t* queue)
{
	if(isEmpty(queue))
	{
		return NULL;
	}
	Customer_t* cust = &queue->customerArray[queue->rear];
	return cust;
}

void enqueue(Queue_t* queue, Customer_t* cust)
{
	if (isFull(queue))
	{
		return;
	}
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->customerArray[queue->rear] = *cust;
	queue->size = queue->size + 1;
}

Customer_t* dequeue(Queue_t* queue)
{
	if (isEmpty(queue))
	{
		return NULL;
	}
	Customer_t* cust = &queue->customerArray[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size + 1;
	return cust;
}

void firstTen(Queue_t* queue, Customer_t* custTen)
{
	int i;
	Queue_t* tempQueue = queue;
	if(queue->size < 10)
	{
		return;
	}
	else
	{
		for(i=0; i<10; ++i)
		{
			custTen[i] = *dequeue(tempQueue);
		}	
	}
	return;
}

//MAIN
int main()
{
Queue_t* mainQueue = createQueue(1000);

int i;

//array
Customer_t firstTenCustomers[10];

//Set up Variables
int numCustServiced = 0;
int numCustRemaining = 0;
float timeSpentInLine = 0.0f;
float timeWait = 0.0f;
float servicedCustomerTime = 0.0f;
float timeClerkIdle = 0.0f;
int Running = 1;
float simTime = 0.0f;
char currentATime [255];
char currentSTime [255];

//Open file
FILE* customers = fopen("./customers", "r");

//First customer exception
fscanf(customers, "%s", currentATime );	
fscanf(customers, "%s", currentSTime);  

//While loop for simulation
while(Running)
{	
	//Create new customer
	Customer_t* newCust = createCustomer((float)(atof(currentATime)),(float)(atof(currentSTime)));
	
	if(simTime >=(float)(atof(currentATime)))
	{
		enqueue(mainQueue, newCust);
		numCustRemaining = numCustRemaining + 1;
		
		//Parse the new customer	
		fscanf(customers, "%s", currentATime);
		fscanf(customers, "%s", currentSTime);  
	
	}
	
		//check for customers served
		if(!isEmpty(mainQueue))
		{
			//Array fill first ten customers
			firstTen(mainQueue, firstTenCustomers);
			numCustRemaining = numCustRemaining + 10;	
			
			if(mainQueue->size >= 10)
			{
				for(i=0; i<10; ++i)
				{
					
					if(firstTenCustomers[i].serviceTime == 0.0f)
					{
						numCustServiced = numCustServiced + 1;
						timeSpentInLine += simTime - servicedCustomerTime - firstTenCustomers[i].arrivalTime;
						timeWait += simTime - firstTenCustomers[i].arrivalTime;
						dequeue(mainQueue);
						servicedCustomerTime = 0.0f;
						numCustRemaining = numCustRemaining - 1;
					}
		
					else
					{
						firstTenCustomers[i].serviceTime = firstTenCustomers[i].serviceTime - 1.0f;
						servicedCustomerTime = servicedCustomerTime + 1;
					}
				}
			}
			else
			{
				if(front(mainQueue)->serviceTime == 0.0f)
				{
					numCustServiced = numCustServiced + 1;
					timeSpentInLine += simTime - servicedCustomerTime - front(mainQueue)->arrivalTime;
					timeWait += simTime - front(mainQueue)->arrivalTime;
					dequeue(mainQueue);
					servicedCustomerTime = 0.0f;
					numCustRemaining = numCustRemaining - 1;
				}
		
				else
				{
				front(mainQueue)->serviceTime = front(mainQueue)->serviceTime - 1.0f;
				servicedCustomerTime = servicedCustomerTime + 1;
				}
			}
		}
		
	//Check for idle checkout clerks
		if(isEmpty(mainQueue))
		{
			++timeClerkIdle;
		}

	++simTime;
	if(simTime >= 3600.0f)
	{
		Running = 0;
	}	

}



//Close the file
fclose(customers);

//Final Calculations from the simulation
printf("Number of Customers Serviced: %d\n", numCustServiced);
printf("Number of Customers Remaining: %d\n", numCustRemaining);
printf("Average time spent by each customer in the line: %f\n", timeSpentInLine/(float)numCustServiced);
printf("Average waiting time for each customer: %f\n", timeWait/numCustServiced);
printf("Average Idle Time for the checkout clerks: %f\n", timeClerkIdle / 10);

return 0;
}

//END OF CODE 
