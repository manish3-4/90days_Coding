 // Online Free C++ compiler to run C++ program online
 #include <bits/stdc++.h>
 using namespace std;
 
 int main() {
     //array
     // vector
     // stack
     // queue
     // linkedlist
     // tree
     // set
     // map
     // multiset
     // pair
    vector<int> arr = {1,2,3,4,6,1,3,6,9,2};
 //    int n = 8;
 //    sort(arr, arr+n); //int array
 //    sort(arr.begin(), arr.end(), [&] ()); // vector
     int n = arr.size();
     cout<<n<<endl;
     arr.push_back(0);
     arr.pop_back();
     cout<<arr[0]<<endl;

     unordered_map<int, pair<int,int>> mp;

        for(auto it: arr){
            mp[it] = {0,0};
        }
        cout<<"map"<<endl;
        for(auto it: mp){
            cout<<it.first<<" "<<it.second.first<<it.second.second<<endl;
        }
        cout<<endl;

        unordered_set<int> s;
        for(auto it: arr){
            s.insert(it);
        }
        
        
        for(auto it: arr){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<"set"<<endl;
    for(auto it: s){
     cout<<it<<" ";
    }
     return 0;
 }