class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        int n=words.size();
        int count=0;
       
        vector<string>save;
        
        for(int i=0;i<n;i++)
        {
              set<char>s;
            for(auto x:words[i])
            {
                s.insert(x);
            }
            
            string str="";
            for(auto y:s)
            {
                str+=y;
            }
            
            save.push_back(str);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(save[i]==save[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
