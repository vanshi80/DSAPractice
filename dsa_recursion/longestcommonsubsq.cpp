#include<stdio.h>
#include<iostream>
using namespace std;
int findsubsequencelength(string str1, string str2, int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }
    if(str1[m-1] == str2[n-1]){
        return 1 + findsubsequencelength(str1,str2,m-1,n-1);
    } 
    return max(findsubsequencelength(str1,str2,m,n-1), findsubsequencelength(str1,str2,m-1,n));
}

int main(){
    string str1 = "abcdgh";
    string str2 = "aedfhr";
    int m = str1.length();
    int n = str2.length();
    cout<<"The length of longest common subsequence is "<<findsubsequencelength(str1,str2,m,n)<<endl;
    return 0;
}