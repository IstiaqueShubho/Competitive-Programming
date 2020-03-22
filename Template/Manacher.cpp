//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

///0-based indexing
///p[0][i] is the maximum length of half palindrome around half index i,even length
///p[1][i] is the maximum length of half palindrome around characters i,odd length

typedef vector<int> VI;
VI pal[2];

void manacher(string str)
{
    int n = str.size(); pal[0] = VI(n+1); pal[1] = VI(n);
    for(int j = 0;j < 2;j++){
        for(int i = 0,l = 0,r = 0;i < n;i++){
            int len = r - i + !j;
            if(i < r) pal[j][i] = min(len,pal[j][l+len]);
            int L = i - pal[j][i],R = i + pal[j][i] - !j;
            while(L > 0 && R < n-1 && str[L-1] == str[R+1])
                pal[j][i]++,L--,R++;
            if(R > r) l = L,r = R;
        }
    }
}

int main()
{
    string str;
    cin >> str;
    manacher(str);
    return 0;
}
