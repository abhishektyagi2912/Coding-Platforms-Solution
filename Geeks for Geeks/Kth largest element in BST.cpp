// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    int solve(Node *root, int k, int& i){
        if(root == NULL) return -1;
        
        int right = solve(root->right,k,i);
        if(right != -1){
            return right;
        }
        i++;
        if(i == k) return root->data;
        return solve(root->left,k,i);
    }
    public:
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int i =0;
        int ans = solve(root,k,i);
        return ans;
    }
};
