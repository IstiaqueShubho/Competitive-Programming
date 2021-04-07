//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
struct query
{
    int l,r,id;
}q[100005];
int arr[100005],ans[100005];
const int k=sqrt(100000);
bool cmp(query &a,query &b)
{
    int block_a=a.l/k;
    int block_b=b.l/k;
    if(block_a==block_b) return a.r<b.r;
    return block_a<block_b;
}
int l=0,r=-1,sum=0;
void add(int x)
{
    sum+=arr[x];
}
void remove(int x)
{
    sum-=arr[x];
}
int main()
{
    int n,Q;
    scanf("%d %d",&n,&Q);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<Q;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q,q+Q,cmp);
    for(int i=0;i<Q;i++){
        while(l>q[i].l) add(--l);
        while(r<q[i].r) add(++r);
        while(l<q[i].l) remove(l++);
        while(r>q[i].r) remove(r--);
        ans[q[i].id]=sum;
    }
    for(int i=0;i<Q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
