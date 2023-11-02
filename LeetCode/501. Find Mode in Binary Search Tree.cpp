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
    void solve(TreeNode* root, vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        vector<int>res;
        unordered_map<int,int>mp;
        int maxi =0;
        solve(root,ans);

        for(auto i : ans){
            mp[i]++;
            maxi = max(maxi,mp[i]);
        }

        for(auto x : mp){
            if(x.second>=maxi) res.push_back(x.first);
        }
        return res;
    }
};
