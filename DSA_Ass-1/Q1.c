#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5};
    int b;
    int val,pos;
    int length = sizeof(a) / sizeof(a[0]);
    int num;
    printf("Enter the number form(2 to 6):");
    scanf("%d",&num);
    switch (num)
    {
    case 2:
        for(int i=0;i<5;i++){
            printf("%d \t",a[i]);
        }
        break;
    case 3:
   
    printf("Enter the number you want to enter:");
    scanf("%d",&val);
    printf("Enter the position where you want to enter number:");
    scanf("%d",&pos);
    for(int i=length-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    length++;
    for(int i=0;i<length;i++){
        printf("%d",a[i]);
    }
    case 4:
    printf("Enter the position where you want to delete number:");
    scanf("%d",&pos);
    for(int i=pos-1;i<length-1;i++){
        a[i]=a[i+1];
    }
    length--;
   for(int i=0;i<length;i++){
    printf("%d \t",a[i]);
   }
 case 5:
  printf("Enter the number you want to search:");
  scanf("%d",&b);
  for(int i=0;i<length;i++){
    if(a[i]==b){
         printf("Number %d found at position %d\n", b, i + 1);
    }
  }

}
return 0;
}