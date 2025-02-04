#include<bits/stdc++.h>
using namespace std;
int main(){
int n = 5;
int arr[] = {1,2,-3,5,6};
stack<int> s;
int ans[5];
int idx = n - 1;
while (idx >= 0)
{
    if (s.empty())
    {
        ans[idx] = -1;
        s.push(arr[idx]);
    }
    else
    {
        auto it = s.top();
        if (it > arr[idx])
        {
            ans[idx] = it;
            s.push(arr[idx]);
        }
        else
        {
            while (!s.empty() && s.top() <= arr[idx])
            {
                s.pop();
            }
            if (s.size() == 0)
                ans[idx] = -1;
            else
                ans[idx] = s.top();
            s.push(arr[idx]);
        }
    }
    idx--;
}
}