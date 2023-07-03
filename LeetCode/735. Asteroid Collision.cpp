class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        int i =0;
        while(i<n){
            if(st.empty()){
                st.push(asteroids[i]);
                i++;
            }
            else{
                if(asteroids[i]<0 && st.top()>0){
                    int a = st.top();
                    st.pop();
                    if(a>abs(asteroids[i])){
                        st.push(a);
                        i++;
                    }
                    else if(a == abs(asteroids[i])){
                        i++;
                    }
                    else if(a < abs(asteroids[i])){
                        continue;
                    }
                    
                }
                else{
                    st.push(asteroids[i]);
                    i++;
                }
            } 
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
