class Solution{
public:
    void insertAtBottom(stack<int> &St , int n, int a){
        //base case
        
        if(St.empty()){
            St.push(n);
            return;
        }
        
        int num = St.top();
        St.pop();
        insertAtBottom(St,n,a-1);
        St.push(num);
    }
    void Reverse(stack<int> &St){
        int a = St.size();
        if(St.empty()){
            return;
        }
        int n = St.top();
        St.pop();
        Reverse(St);
        
        insertAtBottom(St,n,a);
        
    }
};
