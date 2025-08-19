#include<iostream>
using namespace std;
int main(){
    int arr[]={1, 2, 3, 5};
    int n=sizeof(arr)/sizeof(int)+1;
for(int i=0;i<n-1;i++){
    if(arr[0]!=1){
        cout<<"missing number is 1";
    }
  
    if(arr[i+1]!=arr[i]+1){
        cout<<"missing number is: "<<arr[i]+1;
        break;
    }
}
    return 0;
}