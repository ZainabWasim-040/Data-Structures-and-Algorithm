#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int arr[10]={10,20,30,40,50,60,70,80,90,100};
	int n,loc=-1;
	cout<<"Enter any number: ";
	cin>>n;
	for(int i=0;i<10;i++)
		if(arr[i]==n)
		{
			loc=i;
			break;
		}
		if(loc==-1)
		cout<<"Number not found"<<endl;
		else 
		cout<<"Number found at index "<<loc;
		getch();
		return 0;
}
