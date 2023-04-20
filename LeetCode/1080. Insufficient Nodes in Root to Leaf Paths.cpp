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
class Solution {
    TreeNode* solve(TreeNode* root, int limit, int sum){
        if(root == NULL){
            return root;
        }
        if(!root->left && !root->right){
            if(sum+root->val < limit) return NULL;
            else return root;
        }

        TreeNode* l = solve(root->left,limit,sum+root->val);
        TreeNode* r = solve(root->right,limit,sum+root->val);
        if(l == NULL) root->left = NULL;
        if(r == NULL) root->right = NULL;

        if(l == NULL && r == NULL) return NULL;
        return root;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // int sum =0;
        // if(root == NULL){
        //     return root;
        // }
        return solve(root,limit,0);
    }
};
