#include<iostream>
#include<string>

using namespace std;
int main(){
    string str;
    cout<<"enter string :";
    cin>>str;
    int n=str.length();
   
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
       if(str[j]<str[i]){
        swap(str[j],str[i]);
       
       }
    }
}
    cout<<str;
  
    return 0;
}