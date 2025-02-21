class FindElements
{
    unordered_set<int> values;
    void recover(TreeNode *node, int val)
    {
        if (!node)
            return;
        node->val = val;
        values.insert(val);
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode *root)
    {
        if (root)
        {
            recover(root, 0);
        }
    }

    bool find(int target)
    {
        return values.find(target) != values.end();
    }
};

// gfg
class Solution
{
public:
    bool isBalanced(string &str)
    {
        // code here
        stack<char> s;
        for (char ch : str)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }
            else
            {
                if (s.empty())
                    return false;

                char top = s.top();
                s.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return s.empty();
    }
};