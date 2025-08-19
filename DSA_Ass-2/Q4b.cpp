#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter string :";
    cin>>str;
    int n=str.length();
    for(int i=0;i<(n/2);i++){
        int temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    cout<<"reversed string is:"<<str;
    return 0;
}