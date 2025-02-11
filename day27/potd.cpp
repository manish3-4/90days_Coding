

// User function Template for Java

class Solution
{
    // Function to check whether a Binary Tree is BST or not.
    class PrevValue
    {
        Integer value;
    } boolean isBST(Node root)
    {
        PrevValue prev = new PrevValue();
        return isBSTUtil(root, prev);
    }

    // Utility function for recursive in-order traversal to check BST property
    boolean isBSTUtil(Node node, PrevValue prev)
    {
        if (node == null)
            return true;

        // Check left subtree
        if (!isBSTUtil(node.left, prev))
            return false;

        // Check current node
        if (prev.value != null && node.data <= prev.value)
            return false;

        // Update the previous value to current node's value
        prev.value = node.data;

        // Check right subtree
        return isBSTUtil(node.right, prev);
    }
}

// leetcode
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while(s.length()>0 && s.length()>s.find(part)){
               s.erase(s.find(part),part.length());
            }
            return s;
        }
    };