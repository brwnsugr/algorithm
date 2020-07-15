
class Solution {
public:
    vector<vector<int>> d;
    int minPathSum(vector<vector<int>>& grid) {
        int m = int(grid.size());
        int n = int(grid[0].size());
        d.resize(m, vector<int>(n, 0));
        d[0][0] = grid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                else if(i == 0) d[i][j] = grid[i][j] + d[i][j-1];
                else if(j == 0) d[i][j] = grid[i][j] + d[i-1][j];
                else d[i][j] = grid[i][j] + min(d[i-1][j], d[i][j-1]);
            }
        }
        return d[m-1][n-1];
    }
};

//time Limit exceeded Version
class Solution2 {
public:
    vector<vector<int>> d;
    int shortest = 100000000;
    void find(vector<vector<int>>& grid, int row, int col, int length){
        length = length + grid[row][col];
        if(row == int(grid.size()-1) && col == int(grid[0].size()-1)){
            if(length < shortest){
                shortest = length;
                return;
            }
        }
        if(row < grid.size()-1){
            find(grid, row+1, col, length);
        }
        if(col < grid[0].size()-1){
            find(grid, row, col+1, length);
        }
        return;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        find(grid,0,0,0);
        return shortest;
    }
};