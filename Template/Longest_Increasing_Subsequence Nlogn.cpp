//Bismillahir rahmanir rahim
//Lightoj 1421
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

const int maxn = 1e5+5;

int n;
int arr[maxn];
int decdp[maxn],incdp[maxn];

void solvedec()
{
    int tmp[n+5];
    int len = 0;
    for(int i = n-1;i >= 0;i--){
        int idx = lower_bound(tmp,tmp+len,arr[i]) - tmp;
        tmp[idx] = arr[i];
        decdp[i] = idx+1;
        if(idx == len) len++;
    }
}

void solveinc()
{
    vector<int>tmp(n);
    int len = 0;
    for(int i = 0;i < n;i++){
        int idx = lower_bound(tmp.begin(),tmp.begin()+len,arr[i]) - tmp.begin();
        tmp[idx] = arr[i];
        incdp[i] = idx+1;
        if(idx == len) len++;
    }
}

int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&arr[i]);
        }
        memset(decdp,0,sizeof(decdp));
        solvedec();
        memset(incdp,0,sizeof(incdp));
        solveinc();
        int ans = 0;
        for(int i = 0;i < n;i++){
            int tmp = min(incdp[i],decdp[i]) - 1;
            ans = max(ans,2*tmp+1);
        }
        printf("Case %d: %d\n",tc++,ans);
    }
    return 0;
}
