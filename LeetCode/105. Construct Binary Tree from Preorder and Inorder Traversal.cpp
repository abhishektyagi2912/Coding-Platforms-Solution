/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //inorder end = ie
 //inorder start = is
class Solution {
    void fillmap(map<int,int>& m, vector<int>& inorder, int n){
        for(int i =0;i<n;i++){
            m[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preindex, int n, int is, int ie,map<int,int>& m){
        if(preindex >= n || is>ie) return NULL;
        int element = preorder[preindex++];
        TreeNode* root = new TreeNode(element);

        int pos = m[element];
        root->left = solve(preorder,inorder,preindex,n,is,pos-1,m);
        root->right = solve(preorder,inorder,preindex,n,pos+1,ie,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int,int> m;
        fillmap(m,inorder,n);
        int preindex = 0;
        return solve(preorder,inorder,preindex,n,0,n-1,m);
         
    }
};
