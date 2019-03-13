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
    int inv[n+5];
    inv[1] = 1;
    for(int i = 2;i <= n;i++){
        inv[i] = (-(m/i) * inv[m%i] ) % m;
        inv[i] = inv[i] + m;
    }
    return 0;
}

