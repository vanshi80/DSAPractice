#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        // every node has a left and right child
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};
static int idx = -1;
Node* buildTree(vector<int>preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}
int nodescount(Node* root){
    if(root == NULL) return 0;
    int leftCount = nodescount(root->left);
    int rightCount = nodescount(root->right);
    
    return leftCount + rightCount + 1;
}
int main(){
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout<<"Number of nodes in the Tree "<<nodescount(root)<<endl;
    return 0;
}