#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> sum;
        int len = 0, csum = 0;
        
        for(int i = 0; i<arr.size(); i++){
            int value = (arr[i] == 0) ? -1 : 1;
            csum += value;
            
            if(csum == 0){
                len = i+1;
            }
            
            if(sum.find(csum) != sum.end()){
                int slen = i-sum[csum];
                len = max(len,slen);
            }else{
                sum[csum] = i;
            }
        }
        return len;
    }
};



int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string line;
        getline(cin, line); 

        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        Solution obj;

        cout << obj.maxLen(a) << endl;
    }

    return 0;
}