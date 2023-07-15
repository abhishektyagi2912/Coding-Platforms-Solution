class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* temp = q.front();
                q.pop();

                if(size==0) temp->next = NULL;
                else temp->next=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};
