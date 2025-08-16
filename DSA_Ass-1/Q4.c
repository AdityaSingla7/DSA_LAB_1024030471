#include<stdio.h>
int main(){
// int arr[6]={0,1,2,3,4,5};
// int temp;
// int n = sizeof(arr) / sizeof(arr[0]);
// for(int i=0;i<n/2;i++){
//     temp=arr[i];
//     arr[i]=arr[n-i-1];
//     arr[n-i-1]=temp;
    
// }
// for(int i=0;i<n;i++){
//     printf("%d",arr[i]);
// }


int a[3][3];
int b[3][2];
int c[3][2];
int i;
int j;
printf("The first matrix is:");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("The second matrix is:");
for(i=0;i<3;i++){
    for(j=0;j<2;j++){
        scanf("%d",&b[i][j]);
    }
}
for( i=0;i<3;i++){
    for(j=0;j<2;j++){
        int sum=0;
        for(int k=0;k<3;k++){
          sum= sum+a[i][k]*b[k][j];
          
        }
        c[i][j]=sum;
    }
}
printf("The mutiplication matrix is:\n");

for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
        printf("%d ",c[i][j]);
    }
    printf("\n");
}


// int a[2][3];
// int i;
// int j;
// for(int i=0;i<2;i++){
//     for(int j=0;j<3;j++){
//         scanf("%d",&a[i][j]);
//     }
// }
// for(int i=0;i<3;i++){
//     for(int j=0;j<2;j++){
//         printf("%d \t",a[j][i]);
//     }
//     printf("\n");
// }

    return 0;
}