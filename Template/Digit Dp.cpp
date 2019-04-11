//Bismillahir rahmanir rahim
//Lightoj 1068
#include<bits/stdc++.h>
using namespace std;
vector<int>num;
int len,k;
int dp[20][2][100][100];
int solve(int pos,bool sml,int sum,int rem)
{
    if(pos==len){
        if(sum%k==0 && rem%k==0) return 1;
        return 0;
    }
    int &ret=dp[pos][sml][sum][rem];
    if(ret!=-1) return ret;
    ret=0;
    int limit=num[pos];
    if(sml) limit=9;
    for(int i=0;i<=limit;i++){
        int nsml=sml;
        if(sml==0 && i<num[pos]) nsml=1;
        ret+=solve(pos+1,nsml,(sum+i)%k,(rem*10+i)%k);
    }
    return ret;
}
int cal(int x)
{
    num.clear();
    while(x){
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    len=num.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0,0);
}
int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d %d %d",&l,&r,&k);
        if(k>90){
            printf("Case %d: 0\n",tc++);
        }
        else{
            printf("Case %d: %d\n",tc++,cal(r)-cal(l-1));
        }
    }
    return 0;
}
