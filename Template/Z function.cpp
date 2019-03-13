//Length of the longest common prefix between s and the suffix of s starting at i.
//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define FastIo ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> z_function(string s)
{
    int n=s.size();
    vector<int>z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i <= r) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i]-1 > r) l = i,r = i+z[i]-1;
    }
    return z;
}
int main()
{
    string s;
    cin >> s;
    vector<int> z=z_function(s);
    for(int i=1;i<s.size();i++) cout << z[i] << " ";
    cout << "\n";
    return 0;
}

