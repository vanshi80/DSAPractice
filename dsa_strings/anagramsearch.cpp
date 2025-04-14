#include<stdio.h>
#include<iostream>
using namespace std;
bool isSame(int a1[],int a2[]){
    for(int i=0;i<256;i++){
        if(a1[i]!=a2[i]){
            return false;
        }
    }
    return true;
}
bool foundanagram(string &text, string &pattern){
    int CT[256] = {0};
    int CP[256] = {0};
    // Forming a pattern length window
    for(int i = 0;i< pattern.length() ;i++){
        CT[text[i]]++;
        CP[pattern[i]]++;
    }
    // here we got at the last index but the last window formed does not get checked by the isSame step so we have to do it at last
    for(int j = pattern.length();j<text.length();j++){
        if(isSame(CP,CT)){
            return true;
        }
        CT[text[j]]++;  //here we are adding a new element to the window
        CT[text[j-pattern.length()]]--; //here we are removing the first element of the window to form the new window
    }
    // This return statement checks the last window as well which theh for loop misses
    return (isSame(CP,CT));
}
int main(){
    string text = "geekseeksforg";
    string pattern = "frog";
    if(foundanagram(text,pattern)) cout<<"Found the given pattern the string"<<endl;
    else cout<<"Pattern not found"<<endl;
}