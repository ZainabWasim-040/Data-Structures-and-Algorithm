#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
class LinkedList 
{
private:
    Node* head;
public:
    LinkedList() 
	{
        head=NULL;
    }
    ~LinkedList() 
	{
        Node*current=head;
        while(current!=NULL) 
		{
            Node*next=current->next;
            delete current;
            current=next;
        }
        head=NULL;
    }
    void insertAtBeginning(int newData)
	{
        Node*newNode=new Node;
        newNode->data=newData;
        newNode->next=head;
        head=newNode;
    }
    void deleteFromBeginning()
	{
        if(head==NULL) 
		{
            cout<<"List is empty. Cannot delete."<<endl;
            return;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    void insertAtEnd(int newData) 
	{
        Node*newNode=new Node;
        newNode->data=newData;
        newNode->next=NULL;
        if(head==NULL) 
		{
            head=newNode;
            return;
        }
        Node*current=head;
        while(current->next!=NULL) 
		{
            current=current->next;
        }
        current->next=newNode;
    }
    void deleteFromEnd() 
	{
        if(head==NULL) 
		{
            cout<<"List is empty. Cannot delete."<<endl;
            return;
        }
        if(head->next==NULL) 
		{
            delete head;
            head=NULL;
            return;
        }
        Node* current=head;
        Node* prev=NULL;
        while(current->next!=NULL)
		{
            prev=current;
            current=current->next;
        }
        delete current;
        prev->next =NULL;
    }
    void insertAtPosition(int position,int newData)
	{
        if(position<=0) 
		{
            cout<<"Invalid position."<<endl;
            return;
        }
        if(position==1)
		{
            insertAtBeginning(newData);
            return;
        }
        Node* newNode=new Node;
        newNode->data=newData;
        newNode->next=NULL;
        Node* current=head;
        for(int i=1;i<position-1 && current!=NULL;++i)
		{
            current=current->next;
        }
        if(current==NULL) 
		{
            cout<<"Invalid position."<<endl;
            delete newNode;
            return;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
    void deleteFromPosition(int position)
	{
        if(position<=0 || head==NULL) 
		{
            cout<<"Invalid position or empty list."<<endl;
            return;
        }
        if(position==1) 
		{
            deleteFromBeginning();
            return;
        }
        Node* current=head;
        Node* prev=NULL;
        for(int i=1;i<position && current!=NULL;++i)
		{
            prev=current;
            current=current->next;
        }
        if(current==NULL) 
		{
            cout<<"Invalid position."<<endl;
            return;
        }
        prev->next=current->next;
        delete current;
    }
    void display() 
	{
        if(head==NULL)
		{
            cout<<"List is empty."<<endl;
            return;
        }
        Node* current=head;
        cout<<"Linked list: ";
        while(current!=NULL) 
		{
            cout<<current->data<< " ";
            current=current->next;
        }
        cout<<endl;
    }
};
int main() 
{
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.display(); // Should print: 30 20 10
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display(); // Should print: 30 20 10 40 50
    list.insertAtPosition(7, 25);
    list.display(); // Should print: 30 20 25 10 40 50
    list.deleteFromBeginning();
    list.display(); // Should print: 20 25 10 40 50
    list.deleteFromEnd();
    list.display(); // Should print: 20 25 10 40
    list.deleteFromPosition(7);
    list.display(); // Should print: 20 25 40
    return 0;
}

