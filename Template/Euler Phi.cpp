//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//phi(p)=p-1 && phi(p^k)=p^(k-1)*(p-1) when p=PRIME;

int phi[1000005];

void PHI_1_to_n(int n)
{
  for(int i = 1;i <= n;i++){
    phi[i] += i;
    for(int j = i+i;j <= n;j += i){
        phi[j] -= phi[i];
    }
  }
}

int PHI(int n)
{
    int res = n;
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if(n > 1){
        res -= res / n;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    PHI_1_to_n(n);
    cout << PHI(n) << " " << phi[n] << '\n';
    return 0;
}
