//Bismillahir rahmanir rahim
//All pair shortest path cost
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

int cost[105][105];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cost[i][j] = 1e9;
        }
    }
    for(int i = 0;i < m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        cost[u][v] = min(cost[u][v],w);
        cost[v][u] = min(cost[v][u],w);
    }
    for(int i = 1;i <= n;i++) cost[i][i] = 0;
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << i << " -> " << j << " : " << cost[i][j] << "\n";
        }
    }
    return 0;
}
