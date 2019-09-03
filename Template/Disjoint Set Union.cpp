//Bismillahir rahmanir rahim
//Codeforces 1213G
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

const int maxn = 2e5+5;
vector<pair<int,pair<int,int> > >edges;
int Par[maxn];
int Size[maxn];
ll res[maxn];

int findparent(int n)
{
    if(Par[n] == n) return n;
    return Par[n] = findparent(Par[n]);
}

void Union(int a,int b)
{
    if(Size[a] > Size[b]){
        Par[b] = a;
        Size[a] += Size[b];
    }
    else{
        Par[a] = b;
        Size[b] += Size[a];
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n-1;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i = 1;i <= n;i++) Par[i] = i,Size[i] = 1;
    ll ans = 0;
    for(auto x : edges){
        int w = x.ff;
        int u = x.ss.ff;
        int v = x.ss.ss;
        int a = findparent(u);
        ans -= (1LL*Size[a]*(Size[a]-1))/2;;
        int b = findparent(v);
        ans -= (1LL*Size[b]*(Size[b]-1))/2;;
        Union(a,b);
        int y = findparent(a);
        ans += (1LL*Size[y]*(Size[y]-1))/2;
        res[w] = ans;
    }
    for(int i = 1;i <= maxn;i++) if(res[i] == 0LL) res[i] = res[i-1];
    for(int i = 0;i < m;i++){
        int q;
        scanf("%d",&q);
        printf("%lld ",res[q]);
    }
    return 0;
}
