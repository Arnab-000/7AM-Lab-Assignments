/*

 Author : Catalyst71
 < While there is a code, there is a bug > ¯\_(ツ)_/¯

*/

#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nn endl
#define sp " "
#define ff(i,start,n) for(i=start;i<=n;i++)
#define fx(s) for(auto &x:s)
#define check(i) cout << i << endl
#define EPS 1e-10
#define frs first
#define sec second
#define mp make_pair
#define vl vector<ll>
#define vi vector<int>
#define dbp cout << " = Working = " << endl;
#define aff cout <<  "YES"   << endl;
#define neg cout << "NO" <<endl;
#define inn(n) scanf("%d", &n);
#define innm(n,m) scanf("%d%d",&n,&m);
#define outnn(n) printf("%d\n",n);
#define outsn(n) printf("%d ",n);
#define R return;
#define ffin(n) for(int i=0;i<(n);i++)
#define ffjn(n) for(int j=0;j<(n);j++)
#define ffkn(n) for(int k=0;k<(n);k++)
#define FRW {freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};
int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};

//bool isSquare(ll x){ll sq=sqrt(x);return sq*sq==x;}
//long long int gcd(long long int a , long long int b){if(a%b==0)return b;if(b==0)return a;return gcd(b,a%b);}
//long long int lcm(long long int a , long long int b){ return (a / gcd(a, b)) * b;}
//int isprime(long long n){if(n==1)return 0;if(n==2||n==3)return 1;if(n % 2 == 0) return 0;for(long long i = 2; i * i <= n; i++){if(n % i == 0){return 0;}}return 1;}
//int egcd(int a,int b,int &x,int &y){if(b==0){x=1;y=0;return a;}int x1,y1;int d=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return d;}
/*struct vobon
{
    int roll,age;
    string name ;
};*/





void solve()
{
    /* check FIO if not using C IO */
    string s;
    vector<string> vs;

    while (getline(cin, s)) {
        vs.push_back(s);
    }
    for (ll i = 0; i < vs.size(); i += 2) {
        stringstream ss1(vs[i]);
        stringstream ss2(vs[i + 1]);
        vector<ll> a;
        vector<ll> vx;
        vector<ll> ans;
        ll token;
        while (ss1 >> token) {
            a.push_back(token);
        }
        while (ss2 >> token) {
            vx.push_back(token);
        }

        reverse(all(a));
        for (ll k = 0;  k < vx.size(); k++) {
            ll x = vx[k];
            ll n = a.size();
            ll p[n];
            p[n - 1] = a[n - 1];
            for (ll i = n - 2; i >= 0; i--) {
                p[i] = p[i + 1] * x + a[i];
            }
            ans.pb(p[0]);
        }
        cout << ans[0] ;
        for(int j = 1; j < ans.size(); j++){
            cout << " " << ans[j];
        }
        cout << "\n";

    }
}





int main()
{
    FIO

//auto  START = std::chrono::steady_clock::now();
    int t = 1 ;
    //cin >> t ;
    while (t--)
    {
        solve();
    }
//auto  END = std::chrono::steady_clock::now();
//double MMM = double(std::chrono::duration_cast <std::chrono::nanoseconds>(END-START).count());
//cout<<"Shomoy gese : "<<MMM/1e9<<" sec"<<endl;
    return 0 ;
}
