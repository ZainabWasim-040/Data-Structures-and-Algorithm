#include<iostream>
using namespace std;
const int MAX=5;   // maximum size of deque
int Queue[MAX];
int front=-1;
int rear=-1;
// Insert at rear
void enqueueRear(int value) 
{
    if ((rear + 1) % MAX == front)
    {
        cout<<"Queue overflow ";
        return;
    }
    if(front==-1)
	{  // empty queue
        front=rear=0;
    } 
	else if(rear==MAX-1)
	{  // wrap around
        rear=0;
    } 
	else 
	{
        rear++;
    }
    Queue[rear]=value;
    cout<<"Inserted at rear: "<<value<<endl;
}
// Insert at front
void enqueueFront(int value)
{
    if ((rear + 1) % MAX == front)
	{
        cout<<"Queue overflow ";
        return;
    }

    if(front==-1)
	{  // empty queue
        front=rear=0;
    } 
	else if(front==0)
	{  // wrap around
        front=MAX-1;
    }
	else 
	{
        front--;
    }
    Queue[front]=value;
    cout<<"Inserted at front: "<<value<<endl;
}
// Delete from front
void dequeueFront()
{
    if(front==-1)
	{
        cout<<"Underflow ";
        return;
    }
    cout<<"Deleted from front: "<<Queue[front]<<endl;
    if(front==rear) 
	{  // only one element
        front=rear=-1;
    }
	else if(front==MAX-1)
	{
        front=0;
    } 
	else 
	{
        front++;
    }
}
// Delete from rear
void dequeueRear() 
{
    if(front==-1) 
	{
        cout << "Underflow\n";
        return;
    }

    cout << "Deleted from rear: " << Queue[rear] << endl;

    if (front == rear) {  // only one element
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display queue
void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << Queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    enqueueRear(10);
    enqueueRear(20);
    enqueueRear(30);

    display();

    dequeueFront();
    dequeueFront();

    display();

    enqueueRear(40);
    enqueueRear(50);
    enqueueRear(60);  // should show overflow

    display();

    enqueueFront(5);  // insert at front
    display();

    dequeueRear();    // delete from rear
    display();

    return 0;
}
