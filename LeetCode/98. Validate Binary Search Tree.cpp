class Solution {
    bool solve(TreeNode *root, long min_value, long max_value){
        if(root==NULL){
            return true;
        }
        if(root->val > min_value && root->val < max_value){
            return solve(root->left, min_value, root->val) && solve(root->right, root->val, max_value);
        }
        return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        //we make a two function in this 
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
