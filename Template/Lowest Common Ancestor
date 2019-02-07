//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
int par[1005][20],dep[1005];
vector<int>g[1005];
void dfs(int n,int p)
{
    dep[n]=dep[p]+1;
    par[n][0]=p;
    for(int i=0;i<g[n].size();i++){
        int v=g[n][i];
        if(p!=v){
            dfs(v,n);
        }
    }
}
int lca(int u,int v)
{
    if(dep[v]<dep[u]){
        swap(u,v);
    }
    int dis=dep[v]-dep[u];
    for(int i=0;i<=18;i++){
        if((dis>>i)&1){
            v=par[v][i];
        }
    }
    if(u==v) return u;
    for(int i=18;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int m;
            scanf("%d",&m);
            g[i].clear();
            for(int j=0;j<m;j++){
                int v;
                scanf("%d",&v);
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }
        memset(par,0,sizeof(par));
        memset(dep,0,sizeof(dep));
        dfs(1,0);
        for(int i=1;i<=18;i++){
            for(int j=1;j<=n;j++){
                par[j][i]=par[par[j][i-1]][i-1];
            }
        }
        printf("Case %d:\n",tc++);
        int q;
        scanf("%d",&q);
        while(q--){
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",lca(x,y));
        }
    }
    return 0;
}
