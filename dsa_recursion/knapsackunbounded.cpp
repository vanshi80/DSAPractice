// we are given a knapsack(thaila) of some weight and a set of values in val[] and their weights in w[] and we have to fill the thaila in 
// such a way so as to maximize the values in it and without exceeding the limit of knapsack
#include<stdio.h>
#include<iostream>
using namespace std;
int maxvaluesinknap(int w,int wt[],int val[],int n){
    if(w == 0 || n == 0){
        return 0;
    }
    if(wt[n-1] > w){
        return maxvaluesinknap(w,wt,val,n-1);
    }
    return max(maxvaluesinknap(w,wt,val,n-1), val[n-1] + maxvaluesinknap(w-wt[n-1],wt,val,n));
}
int main(){
    int val[] = {10,40,30,50};
    int wt[] = {5,4,6,3};
    int w = 10;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<"The maximum values you can put to knapsack are "<<maxvaluesinknap(w,wt,val,n)<<endl;
}