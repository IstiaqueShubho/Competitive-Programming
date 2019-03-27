//Bismillahir rahmanir rahim
//Lightoj 1096
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
const ll mod = 10007;
const int maxn = 5;
using namespace std;
struct matrix
{
    ll mat[maxn+5][maxn+5];
    int sz;
    matrix(){}
    matrix(int len){
        sz = len;
        for(int i = 0;i < sz;i++){
            for(int j = 0;j < sz;j++){
                mat[i][j] = (i == j);
            }
        }
    }
    matrix operator * (const matrix &m){
        matrix ret;
        memset(ret.mat,0,sizeof(ret.mat));
        ret.sz = m.sz;
        for(int i = 0;i < sz;i++){
            for(int j = 0;j < sz;j++){
                ll res = 0;
                for(int k = 0;k < sz;k++){
                    res += (mat[i][k] * m.mat[k][j]);
                    if(res > mod) res %= mod;
                }
                ret.mat[i][j] = res;
            }
        }
        return ret;
    }
};
matrix expo(matrix &m,ll p)
{
    matrix ret = matrix(m.sz),tmp = m;
    while(p){
        if(p&1) ret = ret * tmp;
        tmp = tmp * tmp;
        p >>= 1;
    }
    return ret;
}
int main()
{
    int t,tc = 1;
    scanf("%d",&t);
    while(t--){
        int n,a,b,c;
        scanf("%d %d %d %d",&n,&a,&b,&c);
        printf("Case %d: ",tc++);
        if(n <= 2){
            printf("%d\n",0);
        }
        else{
            matrix base,col;
            base.sz = 4;
            base.mat[0][0] = a;
            base.mat[0][1] = 0;
            base.mat[0][2] = b;
            base.mat[0][3] = 1;

            base.mat[1][0] = 1;
            base.mat[1][1] = 0;
            base.mat[1][2] = 0;
            base.mat[1][3] = 0;

            base.mat[2][0] = 0;
            base.mat[2][1] = 1;
            base.mat[2][2] = 0;
            base.mat[2][3] = 0;

            base.mat[3][0] = 0;
            base.mat[3][1] = 0;
            base.mat[3][2] = 0;
            base.mat[3][3] = 1;

            col.sz = 4;

            col.mat[0][0] = 0;
            col.mat[1][0] = 0;
            col.mat[2][0] = 0;
            col.mat[3][0] = c;

            matrix ans = expo(base,n-2);

            ll res = 0;
            for(int i = 0;i < col.sz;i++){
                res += (ans.mat[0][i] * col.mat[i][0]);
                res %= mod;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}

