//leetcode
class ProductOfNumbers {
    private:
        vector<int> prefix; 
    public:
        ProductOfNumbers() {
            prefix = {1}; 
        }
        
        void add(int num) {
            if (num == 0) {
                prefix = {1}; 
            } else {
                prefix.push_back(prefix.back() * num);
            }
        }
        
        int getProduct(int k) {
            if (k >= prefix.size()) return 0; 
            return prefix.back() / prefix[prefix.size() - k - 1];
        }
    };
    
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */

//gfg


//User function Template for Java

class Solution
{
    //Function to fix a given BST where two nodes are swapped.  
  
    Node first = null, second = null;
    Node prev = new Node(Integer.MIN_VALUE); // to store the previous node in inorder traversal
    
    // Function to fix a given BST where two nodes are swapped.
    public Node correctBST(Node root) {
        // Traverse the tree to find the swapped nodes
        inorder(root);
        
        // Swap the values of the two nodes
        int temp = first.data;
        first.data = second.data;
        second.data = temp;
        
        return root;
    }
    
    private void inorder(Node root) {
        if (root == null) return;
        
        // Traverse left subtree
        inorder(root.left);
        
        // Check for violation (current node should be greater than previous node in inorder traversal)
        if (first == null && prev.data > root.data) {
            first = prev;
        }
        
        if (first != null && prev.data > root.data) {
            second = root;
        }
        
        prev = root; // Update prev to current node
        
        // Traverse right subtree
        inorder(root.right);
    }
}
