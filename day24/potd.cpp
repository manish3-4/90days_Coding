class Solution {
    public:
      vector<int> boundaryTraversal(Node *root) {
          vector<int> boundary;
          if (!root) return boundary;
  
          if (!isLeaf(root)) boundary.push_back(root->data);  // Add root if it's not a leaf
  
          addLeftBoundary(root->left, boundary);  // Left boundary
          addLeaves(root, boundary);  // Leaf nodes
          addRightBoundary(root->right, boundary);  // Right boundary (reverse order)
  
          return boundary;
      }
  
    private:
      bool isLeaf(Node *node) {
          return (node->left == NULL && node->right == NULL);
      }
  
      void addLeftBoundary(Node *node, vector<int> &boundary) {
          while (node) {
              if (!isLeaf(node)) boundary.push_back(node->data);
              node = (node->left) ? node->left : node->right;
          }
      }
  
      void addLeaves(Node *node, vector<int> &boundary) {
          if (!node) return;
          if (isLeaf(node)) {
              boundary.push_back(node->data);
              return;
          }
          addLeaves(node->left, boundary);
          addLeaves(node->right, boundary);
      }
  
      void addRightBoundary(Node *node, vector<int> &boundary) {
          stack<int> s;
          while (node) {
              if (!isLeaf(node)) s.push(node->data);
              node = (node->right) ? node->right : node->left;
          }
          while (!s.empty()) {
              boundary.push_back(s.top());
              s.pop();
          }
      }
  };
  //leetcode..
  class NumberContainers {
    public:
        unordered_map<int, int> indexToNumber;  // Maps index -> number
        unordered_map<int, set<int>> numberToIndices;  // Maps number -> sorted indices
    
        NumberContainers() {}
    
        void change(int index, int number) {
            if (indexToNumber.count(index)) {
                int oldNumber = indexToNumber[index];
                numberToIndices[oldNumber].erase(index);
                if (numberToIndices[oldNumber].empty()) {
                    numberToIndices.erase(oldNumber);
                }
            }
    
            indexToNumber[index] = number;
            numberToIndices[number].insert(index);
        }
    
        int find(int number) {
            if (numberToIndices.count(number) && !numberToIndices[number].empty()) {
                return *numberToIndices[number].begin();
            }
            return -1;
        }
    };