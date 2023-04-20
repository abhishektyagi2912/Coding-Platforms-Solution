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
    int widthOfBinaryTree(TreeNode* root) {
        long ans = 0;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int s = q.size();
            long start = q.front().second;
            long end = q.back().second;
            while(s--){
                TreeNode* temp = q.front().first;
                long a = q.front().second;
                q.pop();
                if(temp->left) q.push({temp->left,2*a+1});
                if(temp->right) q.push({temp->right,2*a+2});
            }
            ans = max(end-start+1,ans);
        }
        return ans;
    }
};
