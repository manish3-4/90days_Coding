/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int preIndex = 0, postIndex = 0;
        return construct(preorder, postorder, preIndex, postIndex);
    }

private:
    TreeNode *construct(vector<int> &preorder, vector<int> &postorder, int &preIndex, int &postIndex)
    {
        TreeNode *root = new TreeNode(preorder[preIndex++]);

        if (root->val != postorder[postIndex])
        {
            root->left = construct(preorder, postorder, preIndex, postIndex);
        }
        if (root->val != postorder[postIndex])
        {
            root->right = construct(preorder, postorder, preIndex, postIndex);
        }

        postIndex++;
        return root;
    }
};

//gfg

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};




// class Solution
// {
//     //Function to find the next greater element for each element of the array.
//     public static long[] nextLargerElement(long[] arr, int n)
//     {    // Your code here
//         Stack<Integer> stack = new Stack<>();
//         long[] result = new long[n];
        
//         // Initialize all elements in the result array to -1
//         for (int i = 0; i < n; i++) {
//             result[i] = -1;
//         }
        
//         // Iterate over the array
//         for (int i = 0; i < n; i++) {
//             // While stack is not empty and current element is greater than element at stack's top index
//             while (!stack.isEmpty() && arr[stack.peek()] < arr[i]) {
//                 result[stack.pop()] = arr[i];
//             }
//             // Push current index to the stack
//             stack.push(i);
//         }
        
//         return result;
//         // Your code here
//     } 
// }

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends