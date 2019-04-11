//Bismillahir rahmanir rahim
//Codechef Absolute Difference Sum
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1000000007;
vector<int>num;
ll dp[22][12][2][22][190][2];
ll solve(int pos,int val,int sml,int cnt,int sum,int lead)
{
    if(pos==num.size()) return (1LL * cnt * sum);
    if(dp[pos][val][sml][cnt][sum][lead]!=-1 && sml==1) return dp[pos][val][sml][cnt][sum][lead];
    ll ret=0;
    int limit=num[pos];
    if(sml) limit=9;
    for(int i=0;i<=limit;i++){
        int nlead=lead;
        if(i>0) nlead=1;
        int nsml=sml;
        if(i<num[pos]) nsml=1;
        int nsum=sum;
        if(nlead==1 && i<val) nsum+=abs(val-i);
        ret+=solve(pos+1,val,nsml,cnt+(i==val),nsum,nlead);
        ret %= MOD;
    }
    return dp[pos][val][sml][cnt][sum][lead] = ret;
}
void cal(ll n)
{
    num.clear();
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    while(num.size()<20) num.push_back(0);
    reverse(num.begin(),num.end());
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int t;
    scanf("%d",&t);
    while(t--){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        cal(r);
        ll ansr=0;
        for(int i=1;i<=9;i++){
            ansr+=solve(0,i,0,0,0,0);
        }
        cal(l-1);
        ll ansl=0;
        for(int i=1;i<=9;i++){
            ansl+=solve(0,i,0,0,0,0);
        }
        ll ans=((ansr-ansl)% MOD+MOD) % MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
