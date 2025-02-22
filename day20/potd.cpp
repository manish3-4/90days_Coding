#include<bits/stdc++.h>
using namespace std;

//diameter of tree;
class Solution {
    
    int f(Node* root, int &res){
        if(root == NULL) return 0;
        int l = f(root->left, res);
        int r = f(root->right, res);
        res = max(res, l+r);
        
        return 1 + max(r, l);
    }
    
  public:
    int diameter(Node* root) {
        // Your code here
        int res = 0;
        int ans = f(root, res);
        return res;
    }
};

class Node{
    int val;
    Node* left;
    Node* right;

    public:
        Node(int val){
            this->val=val;
            this->right = nullptr;
            this->left = nullptr;
        }
};

//potd of leetcode;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], ans = nums[0];
        for(int i=1; i<n; i++){
            curr = nums[i] > nums[i-1]? curr + nums[i] : nums[i];
            ans = max(ans, curr);

        }
        return ans;
    }
};