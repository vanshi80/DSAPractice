#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    // when we create a pointer to the string then it is called string literal and the string literals are sotred in read only memory
    // so any modifications made to the string literal causes the program to crash
    char str[] = "abcd efg hijk limmin";
    char *dest = str, *src = str;

    while(*src!='\0'){
       if(*src != ' ' && *src != '\t'){
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
    cout<<str<<endl;
    return 0;
}