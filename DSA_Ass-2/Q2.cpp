#include <iostream>
using namespace std;
int32_t main(){

    int n =7;
    int arr[]={64,34,25,12,22,11,90};
    for(int i=0;i<n;i++){ 
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
              int temp=arr[j+1];
              arr[j+1]=arr[j];
              arr[j]=temp;
            }
        }
    }
       
         for(int i=0;i<n;i++){
        cout <<arr[i]<<" ";
         } 
      
    return 0;
}