class Solution{
    public:
    
    // function to do operations of rotate and delete
    // v: input vector
    // n: size of vector
    int rotateDelete(vector<long long> v, int n){
        
        // Your code here
       
        int k = 1;
       
       while(k <= n){
           rotate(v.begin(), v.begin()+v.size()-1, v.end());
           v.erase(v.begin()+n-k);
           n = v.size();
           k++;
       }
       return v[0];
        
    }
};
