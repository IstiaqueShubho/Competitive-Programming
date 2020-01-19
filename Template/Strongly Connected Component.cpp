//Bismillahir rahmanir rahim
//POJ 2186
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

const int maxn = 10005;
vector<int>g[maxn],newg[maxn];
int tin[maxn],up[maxn],stin[maxn],scc[maxn],sz[maxn];
bool vis[maxn];
int time,cnt;
stack<int>st;

void tarjan(int n)
{
    tin[n] = up[n] = ++time;
    vis[n] = 1;
    st.push(n);
    stin[n] = 1;
    for(int i = 0;i < g[n].size();i++){
        int v = g[n][i];
        if(!vis[v]){
            tarjan(v);
            up[n] = min(up[n],up[v]);
        }
        else if(stin[v]) up[n] = min(up[n],tin[v]);
    }
    if(tin[n] == up[n]){
        cnt++;
        while(true){
            int v = st.top();
            st.pop();
            stin[v] = 0;
            scc[v] = cnt;
            sz[cnt]++;
            if(v == n) break;
        }
    }
}

int solve(int n)
{
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < g[i].size();j++){
            int v = g[i][j];
            if(scc[i] != scc[v]){
                newg[scc[i]].push_back(scc[v]);
            }
        }
    }
    int tmp = 0,num;
    for(int i = 1;i <= cnt;i++){
        if(newg[i].size() == 0){
            tmp++;
            num = i;
        }
    }
    if(tmp == 1) return sz[num];
    else return 0;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    time = 0,cnt = 0;
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            tarjan(i);
        }
    }
    printf("%d\n",solve(n));
    return 0;
}

