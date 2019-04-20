//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;
#define maxn 10005
int up[maxn],tin[maxn];
bool vis[maxn];
int Time;
vector<int>g[maxn];
int ap[maxn];
void dfs(int n,int p)
{
    tin[n] = up[n] = Time++;
    vis[n] = 1;
    int child = 0;
    for(int i = 0;i < g[n].size();i++){
        int v = g[n][i];
        if(v == p) continue;
        if(!vis[v]){
            dfs(v,n);
            up[n] = min(up[n],up[v]);
            if(up[v] >= tin[n] && p != 0){
                ap[n] = 1;
            }
            child++;
        }
        else{
            up[n] = min(up[n],tin[v]);
        }
    }
    if(p == 0 && child > 1) ap[n] = 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) g[i].clear();
    Time = 1;
    for(int i = 0;i < m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    bool ck = 0;
    for(int i = 1;i <= n;i++){
        if(ap[i] == 1){
            printf("Node %d is an Articulation Point\n",i);
            ck = 1;
        }
    }
    if(ck == 0){
        printf("No Articulation Point Found\n");
    }
    return 0;
}


