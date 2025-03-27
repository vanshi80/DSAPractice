#include<stdio.h>
int insert(int arr[],int n,int pos,int x,int cap){
    int idx=pos-1;
    if(n==cap){
        return n;
    }
    for(int i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    arr[idx]=x;
    return n+1;
}
int find_Secondlargest(int arr[],int n){
    int res = -1,largest = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[largest]){
            res=largest;
            largest = i;
        }
        else if(arr[i]<arr[largest]){
            if((res == -1)||(arr[i]>arr[res])){
                res=i;
            }
        }
    }
    return res;
}
int main(){
    int arr[20],n,pos,x;  //Here the capacity of the array is 20 and the numner of elements actually in the array is n
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the position and the element to insert");
    scanf("%d %d",&pos,&x);
    int new_length = insert(arr,n,pos,x,20);
    for(int i=0;i<new_length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int res = find_Secondlargest(arr,new_length);
    printf("The second largest element in array is %d\n",res);
    return 0;
}
