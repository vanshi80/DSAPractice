// we have to find th missing nuber from the range 1 to N for that purpose we could do the sum of all number from 1 to N and then subtract
// the sum of given numbers from it and get the missing number 
// but through bit manipulation it can also be done by doing the xor of numbers from 1 to N and then doing an xor of it from the xor of 
// given numbers 
#include<stdio.h>
int main(){
    int arr[5] = {1,2,3,5},n=5;
    // here we are iven and array containing four elements and here number are from 1 to n that is 5 and we have to find the missing num
    int xor1=0,xor2=0;
    // here we have saved the two loops for finding the two XORs
    for(int i=0;i<n-1;i++){
        xor1 = xor1^arr[i];
        xor2 = xor2^(i+1);
    }
    xor2=xor2^n;  //because in the loop xor with n will be left 
    printf("The missing number is %d\n",xor1^xor2);
    return 0;
}