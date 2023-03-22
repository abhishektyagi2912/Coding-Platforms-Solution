#include <bits/stdc++.h> 

void solve(stack<int>& myStack, int x,int n){
    if(n == 0){
        myStack.push(x);
        return;
    }

    //recursive call
    int num = myStack.top();
    myStack.pop();
    solve(myStack,x,n-1);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    int n = myStack.size();
    solve(myStack,x,n);
    return myStack;
}
