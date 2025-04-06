#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    string str = "suyash will always love vani and keep her with him:)";
    int i = 0;
    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z'){
            // this way we are updating the characters of the string
            // str[i] = b then b-a = 1 and 1+A equals ascii value of B so str[i] becomes B
            str[i] = str[i]-'a'+'A';
        }
        i++;
    }
    cout<<str<<endl;
}