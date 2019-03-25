//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;;
    ll inv[n+5];
    inv[1] = 1;
    for(ll i = 2;i <= n;i++){
        inv[i] = (m - (m/i) * inv[m%i] % m ) % m;
    }
    cout << inv[n] << endl;
    return 0;
}
