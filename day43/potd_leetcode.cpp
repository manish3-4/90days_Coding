#include <bits/stdc++.h>
using namespace std;


class solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0, min_sum = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            min_sum = min(min_sum, sum);
        }
        return abs(max_sum - min_sum);
    }         
};
int main() {
    solution s;
    vector<int> nums = {1, -3, 2, 3, -4};
    cout << s.maxAbsoluteSum(nums) << endl;
    return 0;
}