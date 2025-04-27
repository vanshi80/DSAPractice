// But this solution gives tle error in leetcode because it could be solved in less time with dp here it is taking 2^n exponenetial complexity.
#include<stdio.h>
#include<iostream>
using namespace std;
int climbStairs(int n){
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    // The climbing ways depend upon the previous stair ways and the prev to prev stair ways
    return climbStairs(n-1) + climbStairs(n-2);
}
int main(){
    int ways;
    int n;
    scanf("%d",&n);
    // now we have to determine the no of ways to climb n stairs
    ways = climbStairs(n);
    cout<<"No of ways to climb "<<n<<" chairs are: "<<ways<<endl;
    return 0;
}