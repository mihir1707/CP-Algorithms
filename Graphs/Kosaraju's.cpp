class Kosaraju {
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,stack<int> &st){
        vis[node]=1;
        for(auto& it:adj[node]) if(!vis[it]) dfs(it,vis,adj,st);
        st.push(node);
    }

    void dfs3(int node,vector<int> &vis,vector<vector<int>> &adjT){
        vis[node]=1;
        for(auto& it:adjT[node]) if(!vis[it]) dfs3(it,vis,adjT);
    }

public:
    int kosaraju(int nodes,vector<vector<int>> &adj){
        vector<int> vis(nodes,0);
        stack<int> st;
        for(int i=0;i<nodes;i++) if(!vis[i]) dfs(i,vis,adj,st);

        vector<vector<int>> adjT(nodes);
        for(int i=0;i<nodes;i++){
            vis[i]=0;
            for(auto& it:adj[i]) adjT[it].push_back(i);
        }

        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node,vis,adjT);
            }
        }
        return scc;
    }
};