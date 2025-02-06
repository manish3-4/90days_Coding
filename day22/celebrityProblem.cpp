//1->everyone knows celeb
//2-> celeb doesn't know anyone
#include <bits/stdc++.h>
using namespace std;

int celeb(vector<vector<int>> arr){
    int n=arr.size();
    stack<int> st;
    for(int i=n;i>0; i--){
        st.push(i);
    }
    int count = n;
    while(count>0){
        int first = st.top();
        int second = st.top();
        if(arr[second][first] == 1){
            st.push(first);
        }
        else{
            st.push(second);
        }
        count--;
    }
    return st.top();
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr = {{1,1,0,0},
                               {0,1,0,0},
                               {1,1,1,1},
                               {0,1,1,0}};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    int ans = celeb(arr);
    cout<<ans<<endl;
   
}
