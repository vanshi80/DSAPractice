#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter two numbers a and b: ";
    cin>>a>>b;
    if(a==b){
        cout<<"Both the numbers are same";
    }
    else if(a>b){
        cout<<"a is greater than b";
    }
    else{
        cout<<"b is greater than a";
    }
    return 0;
}