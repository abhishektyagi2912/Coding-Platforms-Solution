class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans=0;
        for(int i=0;i<hours.size();i++){          
           int t=0,x=0;
           for(int j=i;j<hours.size();j++){
                if(hours[j]>8) t++;
                else x++;  
                if(x<t) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};
