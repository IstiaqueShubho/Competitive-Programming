//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

string str,pat;
int lps[100005];
vector<int>ans;
void match()
{
    int j = 0;
    for(int i = 0;i < str.size();i++){
        while(j > 0 && str[i] != pat[j]){
            j = lps[j-1];
        }
        if(str[i] == pat[j]) j++;
        if(j == pat.size()){
            j = lps[j-1];
            ans.push_back(i - pat.size() + 1);
        }
    }
}

void precal()
{
    lps[0] = 0;
    int j = 0;
    for(int i = 1;i < pat.size();i++){
        while(j > 0 && pat[j] != pat[i]){
            j = lps[j-1];
        }
        if(pat[i] == pat[j]) j++;
        lps[i] = j;
    }
}

int main()
{
    cin >> str >> pat;
    precal();
    match();
    cout << "Match Position : ";
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
