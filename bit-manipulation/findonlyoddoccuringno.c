// Here we wil be given an array in which we have to find out the only odd times occuring number
// The solutin is simple find the xor of all the numbers in array then the one which is odd will remain alone at last
#include<stdio.h>
int findOnlyOddOccuring(int arr[],int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}
int main(){
    int n;
    printf("Enter the nubmer of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int res = findOnlyOddOccuring(arr,n);
    printf("The only odd occuring number is %d\n",res);
    return 0;
}