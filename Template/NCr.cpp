//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

const int maxn = 1e5+5;
const int mod = 1e9+7;

int fact[maxn],invfact[maxn];

int pwr(int n,int p)
{
    int ret=1;
    while(p){
        if(p&1) ret=(1LL * ret * n) % mod;
        n=(1LL * n * n) % mod;
        p>>=1;
    }
    return ret;
}

void pre()
{
    fact[0] = 1;
    for(int i = 1;i < maxn;i++) fact[i] = (1ll*fact[i-1]*i) % mod;
    invfact[maxn-1] = pwr(fact[maxn-1],mod-2);
    for(int i = maxn-2;i >= 0;i--) invfact[i] = (1ll*invfact[i+1]*(i+1)) % mod;
}

int nCr(int n,int r)
{
    if(r < 0 || r > n) return 0;
    int tmp = (1ll*invfact[r]*invfact[n-r]) % mod;
    return (1ll * fact[n] * tmp) % mod;
}

int main()
{
    pre();
    int n,r;
    cin >> n >> r;
    cout << nCr(n,r) << '\n';
    return 0;
}
