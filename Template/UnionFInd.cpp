//Bismillahir rahmanir rahim
//Toph act-of-random-kindness
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6+5;
int par[maxn],sz[maxn];
ll res;

int findparent(int u)
{
    if(par[u] == u) return u;
    return par[u] = findparent(par[u]);
}

void Union(int a,int b)
{
    int u = findparent(a),v = findparent(b);
    if(u != v){
        res += 1LL * sz[u] * sz[v]; 
        par[v] = u;
        sz[u] += sz[v];
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i = 1;i <= maxn;i++){
        par[i] = i;
        sz[i] = 1LL;
    }

    for(int i = 0;i < n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        Union(u,v);
        printf("%lld\n",res);
    }
    return 0;
}

