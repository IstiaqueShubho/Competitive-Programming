//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

bool prime(int n)
{
    int sq = sqrt(n);
    for(int i = 2;i <= sq;i++){
        if(n % i == 0) return false;
    }
    return true;
}

int pwr(int n,int p,int MOD)
{
    int ret=1;
    while(p){
        if(p&1) ret=(1LL * ret * n) % MOD;
        n=(1LL * n*n) % MOD;
        p>>=1;
    }
    return ret;
}

int ext_gcd(int a, int b, int *x, int *y)
{
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = ext_gcd(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int modinv(int a,int m)
{
    if(prime(m)){
        return pwr(a,m-2,m);
    }
    else{
        int x,y;
        ext_gcd(a,m,&x,&y);
        x %= m;
        if(x < 0) x += m;
        return x;
    }
}
int main()
{
    int a,m;
    cin >> a >> m;
    cout << modinv(a,m) << endl;
    return 0;
}
