class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        //create a map which store maping of the value in sorted way
        map<int,int> m;
        // queue return the value that is node or it's horizontal distance(hd)
        queue<pair<Node*,int>> q;
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root,0));
        while(!q.empty()){
            //take q.front and pop to empty the stack 
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontnode = temp.first;
            int hd = temp.second;
            
            // if maping of hd is not in m then make sure map the distance
            // m.find is not find NYTHING THEn it return end
            if(m.find(hd) == m.end()){
                m[hd] = frontnode->data;            // first is hd and it is equal to data 
            }
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }

};
