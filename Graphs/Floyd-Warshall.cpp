void floyd_warshall(vector<vector<int>> &v){
    int n=v.size();
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(v[i][k]==-1 || v[k][j]==-1) continue;
                if(v[i][j]==-1) v[i][j]=v[i][k]+v[k][j];
                else v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }
}