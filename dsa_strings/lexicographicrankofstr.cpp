//here we are going the return the lexicographic rank of string given like what combinations could be formed from the chaac in string 
// that form the words smaller than the given string 
#include<stdio.h>
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0 || n == 1) return n;
    return n*factorial(n-1);
}
int main(){
    string st = "Vanshi";
    long long int fact[st.length()] = {0};
    for(int i = 1;i<st.length();i++){
        fact[i] = factorial(i);
    }
    
    return 0;
}