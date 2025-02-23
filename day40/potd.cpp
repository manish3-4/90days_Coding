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