#include<stdio.h>
#include<iostream>
using namespace std;
int editdistance(string str1, string str2, int m,int n){
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(str1[m-1] == str2[n-1]){
        return editdistance(str1,str2,m-1,n-1);
    }
    return 1+ min(editdistance(str1,str2,m,n-1),min(editdistance(str1,str2,m-1,n),editdistance(str1,str2,m-1,n-1)));
}
int main(){
    string str1 = "SATURDAY";
    string str2 = "SUNDAY";
    int m = str1.length();
    int n = str2.length();
    cout<<"The minimum number of operations to convert "<<str1<<" to "<<str2<<" are "<<editdistance(str1,str2,m,n)<<endl;
    return 0;
}