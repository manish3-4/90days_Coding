#include <bits/stdc++.h>
using namespace std;

vector<string> allPosibleSubstrings(string s)
{
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            ans.push_back(s.substr(i, j - i + 1));
        }
    }
    return ans;
}
//using recurssion
string solve(string s, int i, string f)
{
    if (i == s.size())
    {
        return f + " ";
    }
    return solve(s, i + 1, f + s[i]) + solve(s, i + 1, f);
}

int main()
{
    string s = "abc";
    // vector<string> ans = allPosibleSubstrings(s);
    // cout << "All possible substrings of " << s << " are: "<<endl;
    // for (auto x : ans)
    // {
    //     cout << x << " ";
    // }
    string f="";
    cout<<"All possible substrings of are: "<<endl<<solve(s, 0, f);
}