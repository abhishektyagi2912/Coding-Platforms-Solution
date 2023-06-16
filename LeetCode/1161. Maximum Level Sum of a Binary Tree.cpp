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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return root->val;
        }
        int ans=0,level=0;
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int sum=0;
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(sum>maxSum){
                maxSum = sum;
                ans = level;
            }
            
        }
        return ans;
    }
};
