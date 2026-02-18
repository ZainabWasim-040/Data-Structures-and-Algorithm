#include<iostream>
using namespace std;
int main()
{
	int arr[5],i,j,temp;
	for(i=0;i<=4;i++)
	{
		cout<<"Enter values: ";
		cin>>arr[i];
	}
	cout<<"Values of original array: "; //output original array
	for(i=0;i<=4;i++)
	{
		cout<<arr[i]<<"\t";
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"\nValues of array after swapping: ";
	for(i=0;i<5;i++)	
	{
		cout<<arr[i]<<"\t";
	}
}
