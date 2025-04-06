#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    string str = "hello there this is vanshika mittal";
    int inword = 0,i = 0,count = 0;
    while(str[i] != '\0'){
        if(str[i]!= ' '){
            if(!inword){
                count++;
                inword = 1;
            }
        }else{
            inword = 0;
        }
        i++;
    }
    cout<<count<<endl;
    return 0;
}