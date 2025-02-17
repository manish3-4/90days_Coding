class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr)
        {
            minHeap.push(num);

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

// leetcode
class Solution
{
public:
    void backtrack(string &tiles, unordered_set<string> &results, string current)
    {
        if (!current.empty())
        {
            results.insert(current);
        }

        for (int i = 0; i < tiles.size(); i++)
        {
            if (i > 0 && tiles[i] == tiles[i - 1])
                continue;

            string next = current + tiles[i];
            string remaining = tiles.substr(0, i) + tiles.substr(i + 1);

            backtrack(remaining, results, next);
        }
    }

    int numTilePossibilities(string tiles)
    {
        unordered_set<string> results;
        sort(tiles.begin(), tiles.end());
        backtrack(tiles, results, "");
        return results.size();
    }
};