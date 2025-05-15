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
// heihgt calculates as the maximum height of nodes from root to leaf nodes and this height is calculated on the basis of nodes
int height(Node* root){
    if(root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}
int main(){
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout<<"Height of the Tree "<<height(root)<<endl;
    return 0;
}