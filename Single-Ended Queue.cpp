#include<iostream>
using namespace std;
const int MAX=5;           // maximum size of deque
int Queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int value)
{
	if(rear==MAX-1)
	{
		cout<<"Queue overflow ";
	}
	else
	{
		if(front==-1)
		{
			front=0;
			rear++;
		}
		Queue[rear]=value;
	}
}
void dequeue()
{
	if(front==-1 || front>rear)
	cout<<"Underflow";
	else
	{
		cout<<Queue[front];
		front++;
	}
}
int main()
{
	enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    enqueue(40);
    enqueue(50);
    enqueue(60);
}
