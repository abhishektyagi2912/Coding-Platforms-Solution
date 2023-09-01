class Solution {
    vector<int> nextStep(vector<int>& heights,int n){
        vector<int> ans(n) ;
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            int curr = heights[i];
            // find small element otherwise pop
            while(!st.empty() && heights[st.top()] >= curr){
                st.pop();
            }

            if(st.empty()) ans[i] = n;

            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevStep(vector<int>& heights,int n){
        vector<int> ans(n) ;
        stack<int> st;

        for(int i = 0; i< n ; i++ ){
            int curr = heights[i];
            // find small element otherwise pop
            while(!st.empty() && heights[st.top()] >= curr){
                st.pop();
            }

            if(st.empty()) ans[i] = -1;

            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n =  heights.size();

        vector<int> next(n);
        next = nextStep(heights,n);

        vector<int> prev(n);
        prev = prevStep(heights,n);

        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int maxi = l*b;

            ans = max(maxi,ans);
        }
        return ans;
    }
};
