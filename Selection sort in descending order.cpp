#include <iostream>
using namespace std;
int main() 
{
    int arr[5];
    int max, temp;
    for(int i = 0; i < 5; i++) 
	{
        cout << "Enter values in array: ";
        cin >> arr[i];
    }
    for(int i = 0; i < 5; i++) 
	{
        max = i;
        for(int j = i + 1; j < 5; j++) 
		{
            if(arr[j] > arr[max])   // changed sign here
                max = j;
        }
        temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
    }
    cout << "Selection Sorted (Descending): ";
    for(int i = 0; i < 5; i++) 
	{
        cout << arr[i] << "\t";
    }
}
