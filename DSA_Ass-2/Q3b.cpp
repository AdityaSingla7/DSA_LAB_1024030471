#include<iostream>
using namespace std;
int main(){
    int arr[]={1, 2, 3, 4,5,7};
    int n=sizeof(arr)/sizeof(int)+1;
     int left = 0, right = n - 2;

    while (left <= right) {
        int mid = (left + right) / 2;

        // If value matches position+1, missing is on right
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } 
        // Else missing is on left side
        else {
            right = mid - 1;
        }
    
    }
    // Missing number is left+1
    cout<<"missing number is :"<< left + 1;

  
    


    return 0;
}