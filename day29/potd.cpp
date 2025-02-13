class Solution {
    public:
      bool findTarget(Node* root, int target) {
          unordered_set<int> seen;
          return inorder(root, target, seen);
      }
      
  private:
      bool inorder(Node* node, int target, unordered_set<int>& seen) {
          if (!node) return false;
          
          if (inorder(node->left, target, seen)) return true;
          
          if (seen.count(target - node->data)) return true;
          seen.insert(node->data);
          
          return inorder(node->right, target, seen);
      }
  };

  //leetcode
  class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
            int operations = 0;
    
            while (minHeap.top() < k) {
                long long x = minHeap.top(); minHeap.pop();  
                long long y = minHeap.top(); minHeap.pop();  
    
                long long newValue = (x * 2) + y;  
                minHeap.push(newValue);
                operations++;
            }
    
            return operations;
        }
    };