//twoSum
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            unordered_map<int, int> result;
            for (int i = 0; i < n; i++) {
                int comp = target - nums[i];
                if (result.find(comp) != result.end()) {
                    return {result[comp], i};
                }
                result[nums[i]] = i;
            }
            return {};
        }
    };

//3sum
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            int n=nums.size();
            for(int i=0; i<n-2; i++){
                int left = i+1;
                int right = n-1;
                if(i>0 &&nums[i] == nums[i-1]) continue;
                while(left<right){
                    int sum = nums[left] + nums[right] + nums[i];
                    if(sum == 0){ ans.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    left++, right--;}
                    else if(sum<0) left++;
                    else right--;
    
                }
            }
            return ans;
        }
    };

//groupAnagrams
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> anagramGroups;
            
            for (const auto& str : strs) {
                string sortedStr = str;
                sort(sortedStr.begin(), sortedStr.end()); 
                anagramGroups[sortedStr].push_back(str);   
            }
    
            vector<vector<string>> result;
            for (const auto& pair : anagramGroups) {
                result.push_back(pair.second);
            }
    
            return result;
        }
    };

//longestConsecutiveSequence
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            int longest = 0;
    
            for (int num : numSet) {
                if (numSet.find(num - 1) == numSet.end()) {
                    int currentNum = num;
                    int count = 1;
    
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                        currentNum++;
                        count++;
                    }
    
                    longest = max(longest, count);
                }
            }
    
            return longest;
        }
    };

//sortArrayByIncreasingFrequency
class Solution {
    public:
        vector<int> frequencySort(vector<int>& nums) {
            unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
    
            sort(nums.begin(), nums.end(), [&](int a, int b) {
                return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
            });
    
            return nums;
        }
    };

    