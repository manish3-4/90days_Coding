class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string result = "";
        for (int i = 0; i < nums.size(); i++)
        {
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        return result;
    }
};

// gfg
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // code here
    vector<double> getMedian(vector<int> &arr)
    {
        vector<double> result;
        priority_queue<int> left;                             // Max heap (stores smaller half)
        priority_queue<int, vector<int>, greater<int>> right; // Min heap (stores larger half)

        for (int num : arr)
        {
            // Insert into appropriate heap
            if (left.empty() || num <= left.top())
            {
                left.push(num);
            }
            else
            {
                right.push(num);
            }

            // Balance the heaps
            if (left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }
            else if (right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }

            // Compute median
            if (left.size() == right.size())
            {
                result.push_back((left.top() + right.top()) / 2.0);
            }
            else
            {
                result.push_back(left.top());
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends