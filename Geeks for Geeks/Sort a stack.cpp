/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void solve(stack<int> &st, int x){
    // this is the condition wehere the stack is emopty or new number is gretaer the the last number
    //base case
    if(st.empty() || st.top() < x){
        st.push(x);
        return;
    }
    
    int ele = st.top();
    st.pop();
    //recuresive call
    solve(st,x);
    
    st.push(ele);
}
void Sort(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }
    int num = st.top();
    st.pop();
    //recursive call
    Sort(st);
    solve(st,num);
}
void SortedStack :: sort()
{
   //Your code here
   Sort(s);
   
}
