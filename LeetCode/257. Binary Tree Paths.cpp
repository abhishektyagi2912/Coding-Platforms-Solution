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
    void path(TreeNode* root, vector<string>&ans,string value){
        if(root->right==NULL && root->left== NULL){
            ans.push_back(value + to_string(root->val));
            return;
        }
        if(root->left) path(root->left, ans, value+to_string(root->val)+"->");
        if(root->right) path(root->right, ans, value+to_string(root->val)+"->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        path(root,ans,"");
        return ans;
    }
};
