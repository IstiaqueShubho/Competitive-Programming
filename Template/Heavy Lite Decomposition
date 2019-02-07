//Codeforces 165 D
//Update edge black or white
//minimum distance between two nodes using only black node

//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
int par[N][18],dep[N],subtree[N];
int chainhead[N],chainid[N],pos[N],seg[4*N];
vector<int>g[N];
vector<pair<int,int> >edge;
int chain,ind;
void build(int n,int s,int e)
{
    if(s==e){
        seg[n]=0;
        return;
    }
    int l=2*n,r=2*n+1,mid=(s+e)>>1;
    build(l,s,mid);
    build(r,mid+1,e);
    seg[n]=seg[l]+seg[r];
}
void hld(int n,int p)
{
    if(chainhead[chain]==-1) chainhead[chain]=n;
    chainid[n]=chain;
    pos[n]=ind++;
    int special=-1,mx=-1;
    for(int i=0;i<g[n].size();i++){
        int v=g[n][i];
        if(v==p) continue;
        if(subtree[v]>mx){
            special=v;
            mx=subtree[v];
        }
    }
    if(special!=-1) hld(special,n);

    for(int i=0;i<g[n].size();i++){
        int v=g[n][i];
        if(v==p) continue;
        if(v!=special){
            chain++;
            hld(v,n);
        }
    }
}
void update(int n,int s,int e,int us,int ue,int v)
{
    if(s>ue || e<us) return;
    if(s>=us && e<=ue){
        seg[n]=v;
        return;
    }
    int l=2*n,r=2*n+1,mid=(s+e)>>1;
    update(l,s,mid,us,ue,v);
    update(r,mid+1,e,us,ue,v);
    seg[n]=seg[l]+seg[r];
}
void dfs(int n,int p,int d)
{
    par[n][0]=p;
    dep[n]=d;
    subtree[n]=1;
    for(int i=0;i<g[n].size();i++){
        int v=g[n][i];
        if(v==p) continue;
        dfs(v,n,d+1);
        subtree[n]+=subtree[v];
    }
}
int LCA(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    int dis=dep[v]-dep[u];
    for(int i=0;i<18;i++){
        if((dis>>i)&1) v=par[v][i];
    }
    if(u==v) return u;

    for(int i=17;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
int query(int n,int s,int e,int qs,int qe)
{
    if(s>qe || e<qs) return 0;
    if(s>=qs && e<=qe) return seg[n];
    int l=2*n,r=2*n+1,mid=(s+e)>>1;
    int q1=query(l,s,mid,qs,qe);
    int q2=query(r,mid+1,e,qs,qe);
    return q1+q2;
}
int query_chain(int u,int v)
{
    if(u==v) return 0;
    int res=0;
    while(chainid[u]!=chainid[v]){
        res+=query(1,1,ind-1,pos[chainhead[chainid[u]]],pos[u]);
        u=par[chainhead[chainid[u]]][0];
    }
    if(u==v) return res;
    res+=query(1,1,ind-1,pos[v]+1,pos[u]);
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) chainhead[i]=-1;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u,v});
    }

    dfs(1,0,1);
    chain=1,ind=1;
    hld(1,0);
    build(1,1,ind);

    for(int i=1;i<18;i++){
        for(int node=1;node<=n;node++){
            par[node][i]=par[par[node][i-1]][i-1];
        }
    }

    int m;
    scanf("%d",&m);
    while(m--){
        int type;
        scanf("%d",&type);
        if(type==1){
            int x;
            scanf("%d",&x);
            int u=edge[x-1].first;
            int v=edge[x-1].second;
            if(dep[u]>dep[v]){
                update(1,1,ind-1,pos[u],pos[u],0);
            }
            else{
                update(1,1,ind-1,pos[v],pos[v],0);
            }
        }
        else if(type==2){
            int x;
            scanf("%d",&x);
            int u=edge[x-1].first;
            int v=edge[x-1].second;
            if(dep[u]>dep[v]){
                update(1,1,ind-1,pos[u],pos[u],1);
            }
            else{
                update(1,1,ind-1,pos[v],pos[v],1);
            }
        }
        else{
            int u,v;
            scanf("%d %d",&u,&v);
            int lca=LCA(u,v);
            int q1=query_chain(u,lca);
            int q2=query_chain(v,lca);
            int white=q1+q2;
            if(white) printf("-1\n");
            else{
                int dis=dep[u]+dep[v]-2*dep[lca];
                printf("%d\n",dis);
            }
        }
    }
    return 0;
}
