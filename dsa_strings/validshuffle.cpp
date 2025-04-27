#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
bool isValidShuffle(string str1, string str2, string shuffle){
    if(str1.length()+str2.length() != shuffle.length()){
        return false;
    }
    int i = 0,j = 0,k = 0;
    while(k<shuffle.length()){
        if(i < str1.length() && str1[i] == shuffle[k]) i++;
        else if(j < str2.length() && str2[j] == shuffle[k]) j++;
        else break;
        k++;
    }
    if(i<str1.length() || j<str2.length()) return false;
    return true;
}
int main(){
    string str1 = "abc";
    string str2 = "def";
    string shuffle = "adbfce";

    if(isValidShuffle(str1,str2,shuffle)){
        cout<<shuffle<<" is valid shuffle of "<<str1<<" and "<<str2<<endl;
    }
    else{
        cout<<shuffle<<" is not the valid shuffle of "<<str1<<" and "<<str2<<endl;
    }

}