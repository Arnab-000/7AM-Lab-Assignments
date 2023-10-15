#include<bits/stdc++.h>
using namespace std;

vector<double> diffTable(vector<double> x, vector<double> y)
{
    int total = x.size();
    vector<int> del_y[total + total];
    for (int i = 0; i < y.size(); i++) del_y[0].push_back(y[i]);
    for (int i = 1; i < total; i++) {
        for (int j = 0; j + 1 < del_y[i - 1].size(); j++) {
            int first = del_y[i - 1][j];
            int second = del_y[i - 1][j + 1];
            del_y[i].push_back(second - first);
        }
    }
    vector<double> firstValues;
    for (int i = 0; i < total; i++) {
        firstValues.push_back(del_y[i][0]);
    }
    return firstValues;
}


double fact(int n) {
    double mul = 1;
    for (int i =  1; i <= n; i++) {
        mul *= (double)i;
    }
    return mul;
}





int main()
{

    int n = 5;
    vector<double> x(n), fx(n);
    cout << "ENTER 5 VALUE OF x : "; for (auto &i : x) cin >> i;
    cout << "ENTER 5 VALUE OF y = f(x) : "; for (auto &i : fx) cin >> i;

    cout << "ENTER THE VALUE X : ";
    double xv; cin >> xv;

    vector<double> v = diffTable(x, fx);
    double h = x[1] - x[0];
    double u = (xv - x[0]) / h;


    vector<double> firstDerivative = {1.0, ((2.0 * u) - 1.0), ((3.0 * u * u) - (6.0 * u) + 2.0), (4.0 * u * u * u - 18.0 * u * u + 22.0 * u - 6.0)};
    vector<double> secondDerivative = {2.0, 6.0 * (u - 1.0), (6.0 * u * u - 18.0 * u + 11.0)};


    double ans = 0 ;

    for (int i = 0; i < firstDerivative.size(); i++) {
        ans += (firstDerivative[i] * v[i + 1]) / fact(i + 1);
    }

    ans /= h;
    cout << "dy/dx : " << ans << "\n";
    ans = 0 ;
    for (int i = 0; i < secondDerivative.size(); i++) {
        ans += (secondDerivative[i] * v[i + 2] ) / fact(i + 1);
    }
    ans /= (h * h);
    cout << "d^2y/dx^2 : " << ans << "\n";

}
