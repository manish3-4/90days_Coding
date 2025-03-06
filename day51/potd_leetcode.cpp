class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int N = n * n;
        vector<int> freq(N + 1, 0);
        int repeated = -1, missing = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[grid[i][j]]++;
            }
        }

        for (int num = 1; num <= N; num++)
        {
            if (freq[num] == 2)
                repeated = num;
            if (freq[num] == 0)
                missing = num;
        }

        return {repeated, missing};
    }
};