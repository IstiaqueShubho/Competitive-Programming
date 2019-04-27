//Bismillahir rahmanir rahim
//Codeforces 342 E
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;
const int maxn = 100005;
const int INF = 1000000007;
vector<int>g[maxn];
int dep[maxn],parent[maxn][20],vis[maxn],par[maxn],sub[maxn],ans[maxn];
void dfs(int n,int p,int d)
{
    dep[n] = d;
    parent[n][0] = p;
    for(int i = 0;i < g[n].size();i++){
        int v = g[n][i];
        if(v == p) continue;
        dfs(v,n,d+1);
    }
}

int lca(int u,int v)
{
    if(dep[v] < dep[u]) swap(u,v);
    int dis = dep[v] - dep[u];
    for(int i = 0;i <= 18;i++){
        if(((dis >> i) & 1) && parent[v][i] != -1){
            v = parent[v][i];
        }
    }
    if(u == v) return u;
    for(int i = 18;i >= 0;i--){
        if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int dist(int u,int v)
{
    return dep[u] + dep[v] - 2*dep[lca(u,v)];
}

void cal(int n,int p)
{
    sub[n] = 1;
    for(int i = 0;i < g[n].size();i++){
        int v = g[n][i];
        if(v == p || vis[n]) continue;
        cal(v,n);
        sub[n] += sub[v];
    }
}
int centroid(int n,int p,int s)
{
    for(int i = 0;i < g[n].size();i++){
        int v = g[n][i];
        if(v == p) continue;
        if(!vis[v]){
            if(sub[v] > s) return centroid(v,n,s);
        }
    }
    return n;
}

void decompose(int n,int p)
{
    cal(n,p);
    int c = centroid(n,-1,sub[n]/2);
    vis[c] = 1;par[c] = p;
    for(int i = 0;i < g[c].size();i++){
        int v = g[c][i];
        if(!vis[v]){
            decompose(v,c);
        }
    }
}

void update(int n)
{
    for(int v = n;v+1 > 0;v = par[v]){
        ans[v] = min(ans[v],dist(n,v));
    }
}

int query(int n)
{
    int ret = INF;
    for(int v = n;v+1 > 0;v = par[v]){
        ret = min(ret,ans[v] + dist(n,v));
    }
    return ret;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n-1;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1,0);
    decompose(1,-1);
    for(int j = 1;j <= 18;j++){
        for(int i = 1;i <= n;i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
    for(int i = 1;i <= n;i++) ans[i] = INF;
    update(1);
    for(int i = 0;i < m;i++){
        int t,v;
        scanf("%d %d",&t,&v);
        if(t == 1) update(v);
        else printf("%d\n",query(v));
    }
    return 0;
}
