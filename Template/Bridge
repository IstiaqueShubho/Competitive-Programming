//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
vector<int>g[10000];
int tim;
int tin[10000],up[10000];
bool vis[10000];
void dfs(int n,int p)
{
    tin[n]=up[n]=tim++;
    vis[n]=1;
    for(int i=0;i<g[n].size();i++){
        int v=g[n][i];
        if(v==p) continue;
        if(!vis[v]){
            dfs(v,n);
            up[n]=min(up[n],up[v]);
            if(up[v]>tin[n]){
                printf("%d %d is Bridge\n",n,v);
            }
        }
        else{
            up[n]=min(up[n],tin[v]);
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tim=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    return 0;
}
