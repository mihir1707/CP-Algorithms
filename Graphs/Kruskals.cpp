class DSU{
    vector<int> rank,parent,size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;++i) parent[i]=i,size[i]=1;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pu]>rank[pv]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
struct Edge{
    int node,w;
};
void kruskals(int nodes,vector<vector<Edge>> &adj){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<nodes;++i) for(auto& it:adj[i]) edges.push_back({it.w,{i,it.node}});.
    sort(edges.begin(),edges.end());
    DSU ds(nodes);
    int ans=0;
    for(auto& it:edges){
        int u=it.second.first;
        int v=it.second.second;
        int wt=it.first;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            ans+=wt;
            ds.unionBySize(u, v);
        }
    }
}