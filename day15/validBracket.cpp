#include <bits/stdc++.h>

using namespace std;

void genParenthesisUtil(int n, int open, int close,string s, vector<string>& ans) {
  
    if (open == n && close == n) {
        ans.push_back(s);
        return;
    }
  
    if (open < n) {
        genParenthesisUtil(n, open + 1, close,  s + "(", ans);
    }
  
    if (close < open) {
        genParenthesisUtil(n, open, close + 1, s + ")",ans);
    }
}
vector<string> AllParenthesis(int n) {
      
    vector<string> ans;
      if (n > 0)
        genParenthesisUtil(n, 0, 0, "", ans);
    return ans;
}

int main() {
    int n = 2;
    vector<string> ans = AllParenthesis(n);
  
      for(string str : ans) {
          cout << str << endl;
    }
    return 0;
}