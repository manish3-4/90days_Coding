#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dir = {-1,0,1,0,-1};
    bool isValid(int &n, int &x, int &y){
        return (x>=0 and x<n and y>=0 and y<n);
    }
    int markIsland(vector<vector<int>>& grid, int island_number, int &n, int x, int y){
        grid[x][y] = island_number;
        int count = 1;
        for(int i=0; i<4; i++){
            int newx = x+dir[i];
            int newy = y+dir[i+1];
            if(isValid(n, newx, newy) and grid[newx][newy] == 1){
                count+= markIsland(grid, island_number, n, newx, newy);
            }
        }
        return count;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> islandsize;
        int islandnumber=2;

        //mark island
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int island = markIsland(grid, islandnumber, n, i, j);
                    islandsize[islandnumber] = island;
                    islandnumber++;
                }
            }
        }

        //try to convert each 0 to 1 
        int max_size = 0;
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if(grid[x][y] == 0){
                    set<int> islands;
                    for(int i=0; i<4; i++){
                        int newx = x+dir[i];
                        int newy = y+dir[i+1];
                        if(isValid(n, newx, newy)){
                            islands.insert(grid[newx][newy]);
                        }
                    }
                    int currIsland = 1;
                    for(int key:islands){
                        currIsland += islandsize[key];
                    }
                    max_size = max(max_size, currIsland);
                }
            }
        }
        return max_size == 0 ? n*n:max_size;
    }
};

int main(){
    Solution* s = new Solution();
    vector<vector<int>> arr = {{1,0}, {0,1}};
    int ans = s->largestIsland(arr);
    cout<<ans<<endl;
}