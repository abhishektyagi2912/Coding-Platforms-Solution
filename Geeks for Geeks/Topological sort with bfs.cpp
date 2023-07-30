class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V);
	    for(int i =0;i<V;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    //do bfs
	    vector<int>ans;
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        
	        ans.push_back(front);
	        for(auto x: adj[front]){
	            indegree[x]--;
	            if(indegree[x] == 0){
	                q.push(x);
	            }
	        }
	        
	    }
	    return ans;
	}
};
