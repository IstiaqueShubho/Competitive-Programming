//Bismillahir Rahmanir Rahim
// N Power P under Module MOD
#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000000+7;
int pwr(int n,int p)
{
    int ret=1;
    while(p){
        if(p&1) ret=(1LL * ret * n) % MOD;
        n=(1LL * n*n) % MOD;
        p>>=1;
    }
    return ret;
}
int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	int ans=pwr(n,p);
	printf("%d\n",ans);
	return 0;
}
