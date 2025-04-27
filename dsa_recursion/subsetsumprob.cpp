// We have to determine if some subset occurs in the array whose sum matches with the target sum 
// apply the pick not pick approach of recursion
#include<stdio.h>
#include<iostream>
using namespace std;
bool findSubset(int arr[],int k, int n){
    // agr sum 0 hojaye to mtlb subset is found
    if(k == 0){
        return true;
    }
    // agr sare elements khtm hojaye aur sum bhi 0 nhi hua (agr hua hota to phle hi true return hogya hota) to return false
    if(n == 0){
        return false;
    }
    if(arr[n-1] > k){
        return findSubset(arr,k,n-1);
    }
    // exclusion || inclusion 
    // agr ek element ko exclude or include krne se kisi bhi case me se agr true return hota hai to mtlb subset exists
    return findSubset(arr,k,n-1) || findSubset(arr,k-arr[n-1],n-1);
}
int main(){
    int arr[] = {2,4,10,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 9;
    if(findSubset(arr,targetSum,n)){
        cout<<"A subset exists whose sum equals "<<targetSum<<endl;
    }
    else{
        cout<<"No subset exists whose sum equals "<<targetSum<<endl;
    }

}