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
public:
    int a = 0;
    void ans(TreeNode* root, long long t, long long sum){
        if(root==NULL){
            return;
        }
        if(sum+root->val==t){
                a++;
        }
        ans(root->left, t, sum+root->val);
        ans(root->right, t, sum+root->val);  
    }
    void solve(TreeNode* root, long long t){
        if(root==NULL){
            return;
        }
        ans(root, t, 0);
        solve(root->left, t);
        solve(root->right, t);
    }
    int pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return a;
    }
};
