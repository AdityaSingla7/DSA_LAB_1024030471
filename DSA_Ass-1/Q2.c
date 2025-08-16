#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,4,4,4,5,5,5};
int length = sizeof(arr) / sizeof(arr[0]);
for(int i=0;i<length;i++){
    for(int j=i+1;j<length;){
        if(arr[i]==arr[j]){
            for(int k=j;k<length-1;k++){
                arr[k]=arr[k+1];
            }
            length--;
        }else{
            j++;
        }
    }
} 
for(int i=0;i<length;i++){
    printf("%d \t",arr[i]);
}
    return 0;
}