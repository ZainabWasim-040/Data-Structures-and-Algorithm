#include <iostream>
using namespace std;
 
#define SIZE 5
 
int queueArr[SIZE];
int front = -1, rear = -1;
 
// Enqueue (Insert)
void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is Full\n";
    } else {
        if (front == -1) front = 0;
        rear++;
        queueArr[rear] = value;
        cout << value << " inserted\n";
    }
}
 
// Dequeue (Delete)
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
    } else {
        cout << queueArr[front] << " deleted\n";
        front++;
    }
}
 
// Display Queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}
 
// Main Function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
 
    dequeue();
    display();
 
    return 0;
}
