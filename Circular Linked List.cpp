#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node*next;
};
class CircularLinkedList 
{
private:
    Node* tail;   // we keep reference to last node (tail->next = head)
public:
    CircularLinkedList() 
	{
        tail=NULL;
    }
    ~CircularLinkedList() 
	{
        if(tail==NULL)
		 return;
        Node* current=tail->next;   // start from head
        Node* head=current;
        do 
		{
            Node* temp=current;
            current=current->next;
            delete temp;
        } 
		while(current!=head);
        tail=NULL;
    }
    // Insert at beginning
    void insertAtBeginning(int newData) 
	{
        Node* newNode=new Node;
        newNode->data=newData;
        if(tail==NULL) 
		{
            newNode->next=newNode;   // single node points to itself
            tail=newNode;
            return;
        }
        newNode->next=tail->next;    // new node points to old head
        tail->next=newNode;          // last node now points to new head
    }
    // Insert at end
    void insertAtEnd(int newData) 
	{
        Node* newNode=new Node;
        newNode->data=newData;
        if(tail==NULL) 
		{
            newNode->next = newNode;
            tail = newNode;
            return;
        }

        newNode->next = tail->next;    // new node points to head
        tail->next = newNode;          // old tail points to new node
        tail = newNode;                // update tail
    }

    // Insert at position (1-based)
    void insertAtPosition(int position, int newData) {
        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(newData);
            return;
        }

        Node* newNode = new Node;
        newNode->data = newData;

        if (tail ==NULL) {
            cout << "List is empty. Inserting at beginning." << endl;
            newNode->next = newNode;
            tail = newNode;
            return;
        }

        Node* current = tail->next;   // head
        for (int i = 1; i < position - 1 && current->next != tail->next; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) {
            tail = newNode;   // inserted at end
        }
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (tail ==NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* head = tail->next;
        if (head == tail) {           // only one node
            delete head;
            tail =NULL;
            return;
        }

        tail->next = head->next;
        delete head;
    }

    // Delete from end
    void deleteFromEnd() {
        if (tail ==NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (tail->next == tail) {     // only one node
            delete tail;
            tail =NULL;
            return;
        }

        Node* current = tail->next;   // head
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;   // new tail's next = head
        delete tail;
        tail = current;               // update tail
    }

    // Delete from specific position (1-based)
    void deleteFromPosition(int position) {
        if (position <= 0 || tail ==NULL) {
            cout << "Invalid position or empty list." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* current = tail->next;   // head
        Node* prev =NULL;
        int count = 1;

        do {
            if (count == position - 1) {
                prev = current;
            }
            current = current->next;
            count++;
        } while (current != tail->next && count <= position);

        if (count < position) {
            cout << "Invalid position." << endl;
            return;
        }

        prev->next = current->next;
        if (current == tail) {
            tail = prev;              // deleted tail ? update tail
        }
        delete current;
    }

    void display() {
        if (tail ==NULL) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Circular Linked List: ";
        Node* current = tail->next;   // start from head
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.display();           // 30 20 10

    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();           // 30 20 10 40 50

    list.insertAtPosition(3, 25);
    list.display();           // 30 20 25 10 40 50

    list.deleteFromBeginning();
    list.display();           // 20 25 10 40 50

    list.deleteFromEnd();
    list.display();           // 20 25 10 40

    list.deleteFromPosition(2);
    list.display();           // 20 10 40

    return 0;
}
