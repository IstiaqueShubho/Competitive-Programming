//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

const int maxn = 1e5+5;
int base[] = {151,157};
int mod[] = {1000950101,1000950107};

int pwr[2][maxn],_hash[2][maxn];

ll get_hash(int l,int r,int k)
{
    return ((_hash[k][r] - (1LL * _hash[k][l-1] * pwr[k][r-l+1]) % mod[k]) + mod[k]) % mod[k];
}

int main()
{
    for(int j = 0;j <= 1;j++){
        pwr[j][0] = 1;
        for(int i = 1;i < maxn;i++){
            pwr[j][i] = (1LL * pwr[j][i-1] * base[j]) % mod[j];
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        string str;
        cin >> str;
        for(int j = 0;j <= 1;j++){
            _hash[j][0] = 0;
            for(int i = 1;i <= n;i++){
                _hash[j][i] = ((1LL * _hash[j][i-1] * base[j]) % mod[j] + str[i-1]) % mod[j];
            }
        }
        set<pair<ll,ll> >s;
        for(int i = 1;i <= n-k+1;i++){
            s.insert({get_hash(i,i+k-1,0),get_hash(i,i+k-1,1)});
        }
        cout << s.size() << "\n";
    }
    return 0;
}

