#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<int> num;
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            num.push_back(stoi(temp));
            temp = "";
        }
    }
    num.push_back(stoi(temp));
    for (auto &x : num)
        cout << x << " ";
}