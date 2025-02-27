#include <stack>
#include <climits>

class Solution
{
private:
    std::stack<int> mainStack; // Regular stack
    std::stack<int> minStack;  // Stack to store minimum values

public:
    Solution()
    {
        // Constructor - No special initialization needed
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        mainStack.push(x);
        // Push into minStack: If empty OR new element is smaller or equal to the top
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (!mainStack.empty())
        {
            if (mainStack.top() == minStack.top())
            {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        if (!mainStack.empty())
        {
            return mainStack.top();
        }
        return -1; // Return -1 for empty stack case
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (!minStack.empty())
        {
            return minStack.top();
        }
        return -1; // Return -1 for empty stack case
    }
};
