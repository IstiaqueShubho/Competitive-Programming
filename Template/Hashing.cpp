//Bismillahir rahmanir rahim
//Spoj NHAY - A Needle in the Haystack
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define ull unsigned long long
using namespace std;
const int maxn = 1000005;
const int base = 37;       //Prime more than the distinct values
const int mod = 1000000007; //Large Prime
char txt[maxn],pat[maxn];
int pwr[maxn];
int h[maxn];

ll get_hash(int l,int r)
{
    return ((h[r] - (1LL * h[l-1] * pwr[r-l+1]) % mod) + mod) % mod;
}

int main()
{
    pwr[0] = 1;
    for(int i = 1;i <= maxn;i++) pwr[i] = (1LL * pwr[i-1] * base) % mod;
    int n;
    while(scanf("%d",&n) != EOF){
        scanf("%s %s",pat,txt);
        int plen = strlen(pat);
        int tlen = strlen(txt);
        if(plen > tlen){
            printf("\n");
            continue;
        }
        ll Hash = 0;
        for(int i = 1;i <= plen;i++) Hash = ((1LL * Hash * base) % mod + pat[i-1]) % mod;
        h[0] = 0;
        for(int i = 1;i <= tlen;i++){
            h[i] = ((1LL * h[i-1] * base) % mod + txt[i-1]) % mod;
        }
        for(int i = 0;i+plen <= tlen;i++){
            if(get_hash(i+1,i+plen) == Hash) printf("%d\n",i);
        }
    }
    return 0;
}
