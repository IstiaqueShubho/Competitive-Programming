//Bismillahir rahmanir rahim
//Codeforces 1199D
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

const int maxn = 2e5+5;
int arr[maxn];
int tree[4*maxn];
int lazy[4*maxn];

void push_down(int n,int s,int e)
{
    if(s == e){
        arr[s] = max(arr[s],lazy[n]);
    }
    else{
        lazy[2*n] = max(lazy[2*n],lazy[n]);
        lazy[2*n+1] = max(lazy[2*n+1],lazy[n]);
    }
    lazy[n] = -1;
}

void update1(int n,int s,int e,int pos,int val)
{
    if(lazy[n] != -1) push_down(n,s,e);
    if(pos == s && pos == e){
        arr[s] = val;
        return;
    }
    int l = 2*n,r = 2*n+1,mid = (s+e) >> 1;
    if(pos <= mid){
        update1(l,s,mid,pos,val);
    }
    else update1(r,mid+1,e,pos,val);
}

void update2(int n,int s,int e,int us,int ue,int val)
{
    if(lazy[n] != -1) push_down(n,s,e);
    if(s > ue || e < us) return;
    if(s >= us && e <= ue){
        lazy[n] = max(lazy[n],val);
        push_down(n,s,e);
        return;
    }
    int l = 2*n,r = 2*n+1,mid = (s+e) >> 1;
    update2(l,s,mid,us,ue,val);
    update2(r,mid+1,e,us,ue,val);
}

void query(int n,int s,int e,int qs,int qe)
{
    if(lazy[n] != -1) push_down(n,s,e);
    if(s > qe || e < qs) return;
    if(s == qs && e == qe){
        printf("%d ",arr[s]);
        return;
    }
    int l = 2*n,r = 2*n+1,mid = (s+e) >> 1;
    query(l,s,mid,qs,qe);
    query(r,mid+1,e,qs,qe);
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(lazy,-1,sizeof(lazy));
    for(int i = 1;i <= n;i++){
        scanf("%d",&arr[i]);
        update1(1,1,n,i,arr[i]);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int typ;
        scanf("%d",&typ);
        if(typ == 1){
            int p,x;
            scanf("%d %d",&p,&x);
            update1(1,1,n,p,x);
        }
        else{
            int x;
            scanf("%d",&x);
            update2(1,1,n,1,n,x);
        }
    }
    for(int i = 1;i <= n;i++) query(1,1,n,i,i);
    return 0;
}


