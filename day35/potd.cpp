class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int n = pattern.length();
        string result = "";
        int stack[n + 1];
        int index = 0;

        for (int i = 0; i <= n; i++)
        {
            stack[index++] = i + 1;

            if (i == n || pattern[i] == 'I')
            {
                while (index > 0)
                {
                    result += to_string(stack[--index]);
                }
            }
        }

        return result;
    }
};
//gfg
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        auto dist = [](const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
        };
    
    // Sort points based on the squared distance
    sort(points.begin(), points.end(), [&dist](const vector<int>& a, const vector<int>& b) {
        return dist(a) < dist(b);
    });
    
    // Return the first k points
    return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends