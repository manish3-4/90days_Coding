// Time Complexity: O(2^n)
// Space Complexity: O(n)
// leetcode
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
class Solution
{
public:
    vector<int> result;
    int size;

    bool backtrack(int index, vector<int> &seq, vector<bool> &used, int n)
    {
        if (index == size)
            return true; // Successfully filled sequence
        if (seq[index] != 0)
            return backtrack(index + 1, seq, used, n); // Skip filled positions

        for (int num = n; num >= 1; --num)
        { // Start from largest for lexicographical order
            if (used[num])
                continue;

            if (num == 1)
            { // Special case: 1 appears once
                seq[index] = 1;
                used[num] = true;
                if (backtrack(index + 1, seq, used, n))
                    return true;
                seq[index] = 0;
                used[num] = false;
            }
            else
            { // For numbers > 1, check if placement is valid
                int secondIndex = index + num;
                if (secondIndex < size && seq[secondIndex] == 0)
                {
                    seq[index] = seq[secondIndex] = num;
                    used[num] = true;

                    if (backtrack(index + 1, seq, used, n))
                        return true;

                    // Backtrack
                    seq[index] = seq[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        size = 2 * n - 1;
        result.assign(size, 0);
        vector<bool> used(n + 1, false);

        backtrack(0, result, used, n);
        return result;
    }
};

// gfg
//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

class Node
{
    int data;
    Node left;
    Node right;

    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG
{

    static Node buildTree(String str)
    {

        if (str.length() == 0 || str.charAt(0) == 'N')
        {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length)
        {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N"))
            {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N"))
            {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    static void deletetree(Node root)
    {
        if (root == null)
            return;
        deletetree(root.left);
        deletetree(root.right);
        root.left = null;
        root.right = null;
    }

    static void printInorder(Node root)
    {
        if (root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

public
    static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0)
        {
            String s = br.readLine();
            Node root = buildTree(s);

            Tree tr = new Tree();
            ArrayList<Integer> A = tr.serialize(root);
            deletetree(root);
            root = null;

            Node getRoot = tr.deSerialize(A);
            printInorder(getRoot);
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends

/*Complete the given function
Node is as follows:
class Tree{
    int data;
    Tree left,right;
    Tree(int d){
        data=d;
        left=right=null;
    }
}*/

/*Complete the given function
Node is as follows:
class Tree{
    int data;
    Tree left,right;
    Tree(int d){
        data=d;
        left=right=null;
    }
}*/

class Tree
{
    // Function to serialize a tree and return a list containing nodes of tree.
public
    ArrayList<Integer> serialize(Node root)
    {
        ArrayList<Integer> result = new ArrayList<>();
        serializeHelper(root, result);
        return result; // code here
    }
private
    void serializeHelper(Node root, ArrayList<Integer> result)
    {
        if (root == null)
        {
            result.add(-1); // representing null node
        }
        else
        {
            result.add(root.data);
            serializeHelper(root.left, result);
            serializeHelper(root.right, result);
        }
    }

    // Function to deserialize a list and construct the tree.
public
    Node deSerialize(ArrayList<Integer> A)
    {
        if (A == null || A.isEmpty() || A.get(0) == -1)
        {
            return null;
        }
        Queue<Integer> queue = new LinkedList<>(A);
        return deSerializeHelper(queue); // code here
    }
private
    Node deSerializeHelper(Queue<Integer> queue)
    {
        if (queue.isEmpty())
        {
            return null;
        }
        Integer val = queue.poll();
        if (val == -1)
        {
            return null;
        }
        Node root = new Node(val);
        root.left = deSerializeHelper(queue);
        root.right = deSerializeHelper(queue);
        return root;
    }
};
