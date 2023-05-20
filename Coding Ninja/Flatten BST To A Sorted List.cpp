#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root,vector<int>& inorder){
    if(root==NULL) return;
    solve(root->left,inorder);
    inorder.push_back(root->data);
    solve(root->right,inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> inorder;
    solve(root,inorder);
    int n = inorder.size();

    TreeNode<int>* newroot = new TreeNode<int>(inorder[0]);

    TreeNode<int>* curr = newroot;

    for(int i=1;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->right= NULL;
    curr->left = NULL;

    return newroot;

}
