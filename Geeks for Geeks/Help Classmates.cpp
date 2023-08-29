class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int>ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            
            //if s.top>curr then pop
            while(s.top()>=curr){
                s.pop();
            }
            
            // mtlb chota h
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    } 
};
