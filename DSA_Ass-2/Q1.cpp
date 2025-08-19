#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int target=7;
int n=sizeof(arr)/sizeof(int);
        int start=0;
        int end=n-1;
        
        while(start<=end){
        int mid =(start +end)/2;
        if(target>arr[mid]){
            start=mid+1;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
              cout<< "index of target :"<<mid;
              break;
        }

        }
             return 0;
      
    
}