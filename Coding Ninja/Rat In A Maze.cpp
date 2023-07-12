#include <bits/stdc++.h> 

bool isSafe(vector < vector<int>>arr,int n,int x,int y, vector<vector<bool>> visited){
    if((x<n && x>=0) && (y<n && y>=0) && visited[x][y]==0 && arr[x][y]==1){
            return true;
        }
        return false;
}

void solve(vector < vector<int>> arr,int n,vector<string>& ans,int x,int y,string path, vector<vector<bool>>& visited){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //Down
    if(isSafe(arr,n,x+1,y,visited)){
        solve(arr, n,ans ,x+1, y,path+ 'D', visited);

    }

    //Left
    if(isSafe(arr,n,x,y-1,visited)){
        solve(arr, n,ans,x, y-1,path+ 'L', visited);

    }

    //Right
    if(isSafe(arr,n,x,y+1,visited)){
        solve(arr, n,ans,x, y+1,path+ 'R', visited);

    }

    //Up
    if(isSafe(arr,n,x-1,y,visited)){
        solve(arr, n,ans,x-1, y,path+ 'U', visited);

    }

    visited[x][y] = 0;
}


vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));

    if(arr[0][0] == 0) return ans;
    
    string path = "";
    solve(arr,n,ans,0,0,path,visited);

    return ans;
}
