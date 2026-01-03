#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int nodes,vector<vector<pair<int,int>>> &adj,int src){
    vector<int> dist(nodes,1e9),count(nodes,0);
    vector<bool> inQueue(nodes,false);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    inQueue[src]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        inQueue[curr]=false;
        for(auto& it:adj[curr]){
            int child=it.first,wt=it.second;
            if(dist[curr]+wt<dist[child]){
                dist[child]=dist[curr]+wt;
                if(!inQueue[child]){
                    q.push(child);
                    inQueue[child]=true;
                    count[child]++;
                    if(count[child]>nodes) return {-1};
                }
            }
        }
    }
    return dist;
}