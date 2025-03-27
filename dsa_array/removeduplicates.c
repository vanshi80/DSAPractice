#include<stdio.h>
// here in this program we are going to remove the duplicates from the sorted array
int main(){
    int arr[5];
    int n;
    scanf("%d",&n);
    printf("Enter the sorted array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int res=1;
    // here we are comparing the 0th element with the 1st 2nd 3rd and so on until we get the unmatching elemnt and as soon as we
    // get out first unmatching elmeent we will put that at 1st postion now the elemnt at the 1st pos will be compared the remaini
    // elements in the array for unmatching elements if found then place the element one pos after the elem being compared.
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}