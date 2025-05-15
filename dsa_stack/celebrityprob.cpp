 //{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        stack<int>s;
        // now the stack as entries eQUAL TO THE THE row size
        for(int i = 0;i<mat.size();i++){
            s.push(i);
        }
        while(s.size() > 1){
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            if(mat[i][j] == 0){
                s.push(i);
            }
            else{
                s.push(j);
            }
        }
        int celeb = s.top();
        for(int i = 0;i<mat.size();i++){
            if(i!= celeb && mat[celeb][i] == 1 || mat[i][celeb] == 0){
                return -1;
            }
        }
        return celeb;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends