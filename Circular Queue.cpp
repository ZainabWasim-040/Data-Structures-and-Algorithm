#include<iostream>
using namespace std;
const int MAX=5;
int Queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if((rear+1)%MAX==front)
    {
        cout<<"Queue Overflow ";
        return;
    }

    if(front==-1)   // first element
        front=0;

    rear=(rear+1)%MAX;
    Queue[rear]=value;
    cout<<"Inserted: "<<value<<endl;
}
void dequeue()
{
    if(front==-1)
    {
        cout<<"Queue Underflow ";
        return;
    }
    cout<<"Removed: "<<Queue[front]<<endl;
    if(front==rear)   // only one element
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}

void display()
{
    if(front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while(true)
    {
        cout << Queue[i] << " ";
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
