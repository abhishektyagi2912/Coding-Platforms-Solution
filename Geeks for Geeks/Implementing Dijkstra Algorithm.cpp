lass Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> d(V,INT_MAX);
        
        set<pair<int,int>> st;
        d[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int distance = top.first;
            int node = top.second;
            
            st.erase(st.begin());
            
            for(auto neg : adj[node]){
                if(distance + neg[1] < d[neg[0]]){
                    auto record = st.find(make_pair(d[neg[0]], neg[0]));
                    
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    d[neg[0]] = distance + neg[1];
                    st.insert(make_pair(d[neg[0]],neg[0]));
                    
                }
            }
        }
        return d;
    }
};
