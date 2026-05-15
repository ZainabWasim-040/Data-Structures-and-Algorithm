#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node* prev;    // pointer to previous node
    Node* next;    // pointer to next node
};
class DoublyLinkedList
{
private:
    Node* head;
public:
    DoublyLinkedList() 
	{
        head=NULL;
    }
    ~DoublyLinkedList() 
	{
        Node* current = head;
        while (current !=NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head =NULL;
    }

    // a) Insert at beginning
    void insertAtBeginning(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->prev =NULL;
        newNode->next = head;

        if (head !=NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = NULL;

        if (head ==NULL) {
            newNode->prev =NULL;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next !=NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Insert at specific position (1-based)
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

        Node* current = head;
        for (int i = 1; i < position - 1 && current !=NULL; ++i) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Invalid position." << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next !=NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head ==NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head !=NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head ==NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next ==NULL) {
            delete head;
            head =NULL;
            return;
        }

        Node* current = head;
        while (current->next !=NULL) {
            current = current->next;
        }
        current->prev->next =NULL;
        delete current;
    }

    // Delete from specific position (1-based)
    void deleteFromPosition(int position) {
        if (position <= 0 || head ==NULL) {
            cout << "Invalid position or empty list." << endl;
            return;
        }
        if(position==1) 
		{
            deleteFromBeginning();
            return;
        }
        Node*current=head;
        for(int i=1;i<position && current!=NULL;++i)
		{
            current=current->next;
        }
        if(current==NULL) 
		{
            cout<<"Invalid position."<<endl;
            return;
        }
        if(current->prev!=NULL) 
		{
            current->prev->next=current->next;
        }
        if(current->next!=NULL) 
		{
            current->next->prev=current->prev;
        }
        delete current;
    }
    void display()
	{
        if(head==NULL)
		{
            cout<<"List is empty."<<endl;
            return;
        }
        Node*current=head;
        cout<<"Doubly Linked List: ";
        while(current!=NULL)
		{
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};
int main() 
{
    DoublyLinkedList list;
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
