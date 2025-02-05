// leetcode 496

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> s;
    vector<int> ans(n);
    int idx = 2 * n - 1;
    while (idx >= 0)
    {
        if (s.empty())
        {
            s.push(arr[idx % n]);
            ans[idx % n] = -1;
        }
        else
        {
            auto it = s.top();
            if (it >= arr[idx % n])
            {
                while (!s.empty() && s.top() >= arr[idx % n])
                {
                    s.pop();
                }
                if (s.size() == 0)
                    ans[idx % n] = -1;
                else
                    ans[idx % n] = s.top();
                s.push(arr[idx % n]);
            }
            else
            {
                ans[idx % n] = s.top();
                s.push(arr[idx % n]);
            }
        }
        idx--;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
