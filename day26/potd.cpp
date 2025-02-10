class Solution
{
public:
    int counts(Node *node, int k, int curr, unordered_map<int, int> &pre)
    {
        if (node == nullptr)
            return 0;
        int path = 0;
        curr += node->data;

        if (curr == k)
            path++;

        path += pre[curr - k];
        pre[curr]++;

        path += counts(node->left, k, curr, pre);
        path += counts(node->right, k, curr, pre);

        pre[curr]--;

        return path;
    }
    int sumK(Node *root, int k)
    {
        // code here
        if (root == nullptr)
            return 0;

        unordered_map<int, int> prefSums;

        return counts(root, k, 0, prefSums);
    }
};

// leetcode
class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
    
            for(char ch : s){
                if(isdigit(ch)){
                    if(!st.empty()){
                        st.pop();
                    }
                }else{
                    st.push(ch);
                }
            }
            string result = "";
            while(!st.empty()){
                result = st.top() + result;
                st.pop();
            }
            return result;
        }
    };