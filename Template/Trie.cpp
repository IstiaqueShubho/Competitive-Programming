//Bismillahir rahmanir rahim
//Codeforces 706D
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;
int root = 1;
int cur = 1;
int cnt[4000005];
int tree[4000005][2];
void update(int x,int val)
{
    int now = root;
    cnt[now] += val;
    for(int i = 30;i >= 0;i--){
        int c = (x >> i) & 1;
        if(tree[now][c] == 0){
            cur++;
            tree[now][c] = cur;
        }
        now = tree[now][c];
        cnt[now] += val;
    }
}
int query(int x)
{
    int now = root;
    int ans = 0;
    for(int i = 30;i >= 0;i--){
        int c = (x >> i) & 1;
        if(tree[now][1^c] == 0 || cnt[tree[now][1^c]] == 0){
            ans = ans;
        }
        else{
            ans ^= (1 << i);
            c ^= 1;
        }
        now = tree[now][c];
    }
    return ans;
}
int main()
{
    update(0,1);
    char c[5];
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%s %d",c,&x);
        if(c[0] == '+') update(x,1);
        else if(c[0] == '-') update(x,-1);
        else printf("%d\n",query(x));
    }
    return 0;
}
