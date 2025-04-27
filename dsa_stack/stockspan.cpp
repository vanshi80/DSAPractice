#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> findspan(vector<int>price){
    vector<int>ans(price.size(),0);
    stack<int>s;
    for(int i = 0;i<price.size();i++){
        while(!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = i+1;
        }else{
            ans[i] = i-s.top(); 
        }
        s.push(i);
    }
    return ans;
}
int main(){
    vector<int>price = {100,80,60,70,60,75,85};
    vector<int>res = findspan(price);
    for(int r : res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}