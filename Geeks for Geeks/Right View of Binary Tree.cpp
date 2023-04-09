// Should return  right view of tree
class Solution
{
    void rightview(Node* root, vector<int>& ans, int level){
        if(root==NULL){
            return;
        }
        // enter a new level so increase the level
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        rightview(root->right, ans, level+1);
        rightview(root->left,ans, level+1);
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       rightview(root,ans,0);
       return ans;
    }
};
