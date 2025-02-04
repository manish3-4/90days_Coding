class Solution {
    // Function to find the height of a binary tree.
    int height(Node root) {
        // code here
        if(root == null) return -1;
        
        int l = height(root.left);
        int r = height(root.right);
        
        return Math.max(l, r) + 1;
    }
}
