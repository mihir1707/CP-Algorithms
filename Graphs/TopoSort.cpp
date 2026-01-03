class TopoSort{
    int n;
    vector<vector<int>> adj;
    vector<int> vis,ans;
    public:
    TopoSort(int nodes,vector<vector<int>> &adj){
        vis.resize(nodes,0);
        n=nodes;
        this->adj=adj;
    }
    void dfs(int node){
        vis[node]=1;
        for(auto& i:adj[node]) if(!vis[i]) dfs(i);
        ans.push_back(node);
    }
    void bfs(){
        vector<int> indeg(n,0);
        for(int i=0;i<n;++i) for(auto& j:adj[i]) indeg[j]++;
        queue<int> q;
        for(int i=0;i<n;++i) if(!indeg[i]) q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.pb(node);
            for(auto& i:adj[node]){
                indeg[i]--;
                if(!indeg[i]) q.push(i);
            }
        }
    }
    void print(){
        for(auto& i:ans) cout<<i<<" ";
    }
};