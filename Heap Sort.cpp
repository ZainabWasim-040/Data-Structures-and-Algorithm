#include<iostream>
using namespace std;
int main() 
{
    int arr[5];
    for(int i=0;i<5;i++)
    {
    	cout<<"Enter values in array: ";
    	cin>>arr[i];
	}
    int largest,start,end,root;
    for(int i=5/2-1;i>=0;i--) 
	{
        root=i;
        while(true) 
		{                                                           
            largest=root;
            start=2*root+1;
            end=2*root+2;
            if(start<5 && arr[start]>arr[largest])
            {
                largest=start;
            }
            if(end<5 && arr[end]>arr[largest])
            {
		        largest=end;
		    }
            if(largest!=root)
			{
                swap(arr[root],arr[largest]);
                root=largest;
            }  
			else 
			{
                break;
            }
        }
    }
    for(int i=4;i>0;i--)
	{
        swap(arr[0],arr[i]);
        root=0;
        int heap_Size=i;

        while(true)
		{
            largest=root;
            start=2*root+1;
            end=2*root+2;
            if(start<heap_Size && arr[start]>arr[largest])
            {
				largest=start;
			}
            if(end<heap_Size && arr[end]>arr[largest])
            {
                largest=end;
            }
            if(largest!=root) 
			{
                swap(arr[root],arr[largest]);
                root=largest;
            } 
			else 
			{
                break;
            }
        }
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
