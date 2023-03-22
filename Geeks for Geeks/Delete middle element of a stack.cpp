class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int sizeOfStack, int count){
        //base case 
        if(count == sizeOfStack/2){
            s.pop();
            return;
        }
        //recursive call
        int num = s.top();
        s.pop();
        solve(s, sizeOfStack, count+1);
        s.push(num);
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int count = 0;
        solve(s, sizeOfStack, count);
    }
};
