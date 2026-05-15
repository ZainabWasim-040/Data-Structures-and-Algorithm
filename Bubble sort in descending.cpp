#include <iostream>
using namespace std;
 
int main() {
int arr[5] = {5, 2, 4, 1, 3};
 
for(int i = 0; i < 5; i++) {
for(int j = 0; j < 5 - i - 1; j++) {
if(arr[j] < arr[j + 1]) {
// swap
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
 
// print sorted array
for(int i = 0; i < 5; i++) {
cout << arr[i] << " ";
}
 
return 0;
}
