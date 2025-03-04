class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            int remainder = n % 3;
            if (remainder == 2)
                return false; // If remainder is 2, it's not possible
            n /= 3;           // Reduce n by a factor of 3
        }
        return true;
    }
};