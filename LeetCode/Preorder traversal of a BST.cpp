#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* solve(vector<int> &preorder,int s,int e){
    if(s>e) return NULL;

    int mid = (s+e)/2;
    BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(preorder[mid]);
    temp-> left = solve(preorder,s,mid-1);
    temp-> right = solve(preorder,mid+1,e);
    return temp;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here
    sort(preorder.begin(),preorder.end());
    int n = preorder.size()-1;
    return solve(preorder,0,n);
}
