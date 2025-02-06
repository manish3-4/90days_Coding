class Solution
{
public:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

    Node *buildTreeHelper(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preIndex++];
        Node *root = new Node(rootVal);

        int inIndex = inorderMap[rootVal]; // Find index in inorder

        // Recursively build left and right subtrees
        root->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1);
        root->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        // Create a hash map to store inorder indices for quick lookup
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, preorder, 0, inorder.size() - 1);
    }
};

// leetcode

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int count = 0;

        // Generate all pairs and store their products in the map
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                count += 8 * productCount[product];  // Each pair contributes to 8 valid tuples
                productCount[product]++;
            }
        }
        return count;
    }
};
