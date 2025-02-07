//depth of tree
//skew tree, height balance tree
//balance tree
class Solution {
    public:
    int height(TreeNode* node){
        if(node == nullptr) return 0;

        int l = height(node->left);
        int r = height(node->right);

        if(l == -1 || r == -1 || abs(l-r) > 1 ) return -1;

        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return ( height(root) > 0 );
    }
};

//diameter of a bst.
//binary tree max path 
https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/1534649287/

//identical trees