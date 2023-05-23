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
    void solve(TreeNode* root, int targetSum,vector<vector<int>> &ans,vector<int>arr){
        if(root==NULL) return;
        
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            int sum = accumulate(arr.begin(),arr.end(),0);
            if(sum == targetSum){
                ans.push_back(arr);
            }
        }
        solve(root->left,targetSum,ans,arr);
        solve(root->right ,targetSum,ans,arr);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>arr;
        // int sum =0;
        solve(root,targetSum,ans,arr);
        return ans;
    }
};
