//Bismillahir rahmanir rahim
#include<bits/stdc++.h>

using namespace std;

int ext_gcd(int a, int b, int *x, int *y)
{
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = ext_gcd(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int main()
{
    int a,b,x,y;
    cin >> a >> b;
    int gc = ext_gcd(a,b,&x,&y);   // AX + BY = GCD(A,B)
    cout << gc << " " << x << " " << y << endl;
    return 0;
}
