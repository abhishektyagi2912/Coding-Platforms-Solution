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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> a;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        bool ltor = true;
        while(!q.empty()){
            int n = q.size();
            a.clear();
            while(n--){
                TreeNode* p = q.front();
                q.pop();
                a.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
                
            }
            if(!ltor) reverse(a.begin(),a.end());  
            ans.push_back(a);
            if(ltor) ltor = false;
            else ltor = true;
        }
        return ans;
    }
};
