const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int y, int x){
        grid[y][x] = '0';
        for(int i = 0; i < 4; i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if(next_y >= 0 && next_y < grid.size() &&
               next_x >= 0 && next_x < grid[0].size()
               &&grid[next_y][next_x] == '1'){
                dfs(grid, next_y, next_x);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = int(grid.size());
        if(row==0) return 0;
        int col = int(grid[0].size());
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};