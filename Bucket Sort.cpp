#include<iostream>
using namespace std;
int main() 
{
    int arr[5];
    for(int i=0;i<5;i++)
    {
    	cout<<"Enter values in Array: ";
    	cin>>arr[i];
	}
    int buckets[5][5];       
    int Count[5]={0};

    for(int i=0;i<5;i++)
	{
        int Index=arr[i]/20;       
        if(Index>4) 
		Index=4; 
        buckets[Index][Count[Index]++]=arr[i];
    }

    for(int b=0;b<5;b++) 
	{
        for(int i=1;i<Count[b];i++)
		{
            int key=buckets[b][i];
            int j=i-1;
            while(j>=0 && buckets[b][j]>key)
			{
                buckets[b][j+1]=buckets[b][j];
                j--;
            }
            buckets[b][j+1]=key;
        }
    }
    int index=0;
    for(int b=0;b<5;b++) 
	{
        for(int i=0;i<Count[b];i++)
		{
            arr[index++]=buckets[b][i];
        }
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<"\t";
    }

}
