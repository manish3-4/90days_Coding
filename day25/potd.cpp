class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long n = nums.size();
        long long total_pairs = (n * (n - 1)) / 2; // Total pairs in the array

        unordered_map<int, long long> freq; // To store the frequency of new_val[i]
        long long good_pairs = 0;

        for (int i = 0; i < n; ++i)
        {
            int new_val = nums[i] - i;
            if (freq.count(new_val))
            {
                good_pairs += freq[new_val]; // All previous occurrences form good pairs
            }
            freq[new_val]++;
        }

        return total_pairs - good_pairs; // Bad pairs = Total pairs - Good pairs
    }
};


//gfg

class Solution {
    public:
      int ans = INT_MIN;
      int f(Node* node){
          if(node == NULL) return 0;
          int l = max(0, f(node->left));
          int r = max(0, f(node->right));
          ans = max(ans, l+r+node->data);
          return max({0, l+node->data, r+node->data});
      }
      int findMaxSum(Node* node) {
          f(node);
          return ans;
      }
  };~