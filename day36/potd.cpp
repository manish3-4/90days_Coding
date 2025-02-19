class Solution
{
public
    String getHappyString(int n, int k)
    {
        List<String> happyStrings = new ArrayList<>();
        generateHappyStrings("", n, happyStrings);

        if (k > happyStrings.size())
        {
            return "";
        }

        return happyStrings.get(k - 1);
    }

private
    void generateHappyStrings(String current, int n, List<String> happyStrings)
    {
        if (current.length() == n)
        {
            happyStrings.add(current);
            return;
        }

        for (char c : new char[]{'a', 'b', 'c'})
        {
            if (current.length() == 0 || current.charAt(current.length() - 1) != c)
            {
                generateHappyStrings(current + c, n, happyStrings);
            }
        }
    }
}

// gfg
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        // Your code here
        priority_queue<Node *, vector<Node *>, compare> pq;

        for (auto list : arr)
        {
            if (list)
                pq.push(list);
        }

        Node *dummy = new Node(0);
        Node *tail = dummy;

        while (!pq.empty())
        {
            Node *smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next)
            {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};