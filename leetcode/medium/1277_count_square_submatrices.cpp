class Solution {
public:
    Solution(): count(0){}
    
    bool is_big_square(int y, int x, int n, vector<vector<int>>& matrix){
        //horizontal line check
        for(int i = x; i <= x + n; i++){
            if(matrix[y+n][i] == 0){
                return false;
            }
        }
        //vertical line check
        for(int i = y; i <= y + n; i++){
            if(matrix[i][x+n] == 0){
                return false;
            }
        }
        //diagonal point check
        if(matrix[y+n][x+n] == 0) return false;
        return true;
    }
    
    int countSquares(vector<vector<int>>& matrix){
        vector<vector<int>> tmp;
        int count = 0;
        int m = int(matrix.size());
        int n = int(matrix[0].size());
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    count++;
                    int max_len = min(m-i-1, n-j-1);
                    if(max_len == 0) continue;
                    for(int k = 1; k <= max_len; k++){
                        if(!is_big_square(i, j, k, matrix)){
                            break;
                        }
                        count++;
                    }
                }
            }
        }
        return count;
    }
private:
    int count;
};