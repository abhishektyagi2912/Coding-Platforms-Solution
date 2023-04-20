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
    int depth(TreeNode* root){
        // int ans = 0;
        if(root == NULL) return 0;
        // depth(root->left,dep+1);
        // depth(root->right,dep+1);
        int h1 = depth(root->left);
        int h2 = depth(root->right);
        int ans = max(h1,h2)+1;
        // cout<<ans;
        return ans;
    }
    void solve(TreeNode* root,int height,int & ans, int level ){
        if(root==NULL) return;
        if(root->left== NULL && root->right== NULL && level == height) ans += root->val;
        solve(root->left,height,ans,level+1);
        solve(root->right,height,ans,level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int ans = 0 ;
        int height = depth(root);
        // cout<<height;

        solve(root,height,ans,1);
        return ans;
    }
};
