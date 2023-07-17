#include<bits/stdc++.h>
using namespace std;

int main()
{
    /// Given  f(x) = x3 - 2x2 + 5x + 10  by using Horner's rule x = 5.
    int x = 5, n = 3;
    int a[4] = {10,5,-2,1};
    int p[4];
    p[3] = a[3];
    for(int i = 2; i >=0; i--){
        p[i] = p[i+1] * x + a[i];
    }
    cout << "Solution of the equation is : " << p[0] << "\n";
}
