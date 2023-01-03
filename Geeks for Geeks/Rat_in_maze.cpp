class Solution{
    bool isSafe(vector<vector<int>> &m,int n,vector<vector<int>> visited,int x,int y){
        if((x<n && x>=0) && (y<n && y>=0) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        return false;
    }
    void ratprob(vector<vector<int>> &m,int n,vector<string> &ans,int x,int y,vector<vector<int>> visited,string s){
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        }
        visited[x][y]=1;
        
        //left check
        int newx=x;
        int newy=y-1;
        if(isSafe(m,n,visited,newx,newy)){
            s.push_back('L');
            ratprob(m,n,ans,newx,newy,visited,s);
            s.pop_back();
        }
        //right check
        newx=x;
        newy=y+1;
        if(isSafe(m,n,visited,newx,newy)){
            s.push_back('R');
            ratprob(m,n,ans,newx,newy,visited,s);
            s.pop_back();
        }
        //down check
        newx=x+1;
        newy=y;
        if(isSafe(m,n,visited,newx,newy)){
            s.push_back('D');
            ratprob(m,n,ans,newx,newy,visited,s);
            s.pop_back();
        }
        //Up check
        newx=x-1;
        newy=y;
        if(isSafe(m,n,visited,newx,newy)){
            s.push_back('U');
            ratprob(m,n,ans,newx,newy,visited,s);
            s.pop_back();
        }
        
        visited[x][y]=0; //for recusrive call to check all the paths
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        //if starting point is zero
        if(m[0][0]==0) return ans;
        
        int x=0,y=0;
        
        //form a new vector that is called visited vector
        vector<vector<int>> visited = m;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        string s="";    //path 
        ratprob(m,n,ans,x,y,visited,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    
