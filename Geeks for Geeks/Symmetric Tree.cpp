class Solution{
    bool symmetric(Node* left,Node* right){
        if(left==NULL && right == NULL){
            return true;
        }
        if(left==NULL && right != NULL){
            return false;
        }
        if(left!=NULL && right == NULL){
            return false;
        }
        if(left->data!=right->data){
            return false;
        }
        return (symmetric(left->left,right->right)&&symmetric(left->right,right->left));
    }
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return true;
	    return symmetric(root->left,root->right);
    }
};
