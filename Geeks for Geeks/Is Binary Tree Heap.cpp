// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int countnodes(struct Node* root){
      if(root==NULL){
          return 0;
      }
      int ans = 1+ countnodes(root->left)+ countnodes(root->right);
      return ans;
  }
  bool iscbt(struct Node* root, int index, int count){
      if(root == NULL) return true;
      if(index>=count) return false;
      else{
          bool left = iscbt(root->left,2*index+1,count);
          bool right = iscbt(root->right,2*index+2,count);
          return (left && right);
      }
  }
  bool ismaxorder(struct Node* root){
      if(root->left == NULL && root->right == NULL){
          return true;
      }
      if(root->right==NULL){
          return (root->data>root->left->data);
      }
      else{
          bool left = ismaxorder(root->left);
          bool right = ismaxorder(root->right);
          return (left && right && (root->data>root->left->data && root->data>root->right->data));
      }
  }
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int totalcount = countnodes(tree);
        if(iscbt(tree,index,totalcount) && ismaxorder(tree)){
            return true;
        }
        else false;
    }
};
