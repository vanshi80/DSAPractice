#include<stdio.h>
#include<iostream>
using namespace std;
void findsubsets(string str,int index, string curr){
    int n = str.length();
    if(index == n){
        cout<<curr<<endl;
        return;
    }
    findsubsets(str,index+1,curr); //exclusion case
    findsubsets(str,index+1,curr+str[index]);
}
int main(){
    string str = "abc";
    int index = 0;
    string curr = " ";
    findsubsets(str,index,curr);
    return 0;
}