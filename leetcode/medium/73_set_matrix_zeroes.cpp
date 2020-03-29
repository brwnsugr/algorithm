// Time Complexity: O(M*N), Space Complexity: O(M+N) 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //find zero valued location
        unordered_set<int> zero_rows;
        unordered_set<int> zero_cols;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j <matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    zero_rows.insert(i);
                    zero_cols.insert(j);
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j <matrix[i].size(); j++){
                if(zero_rows.find(i) != zero_rows.end()
                   || zero_cols.find(j)!=zero_cols.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// TC: O((M*N)*(M+N)) SC: O(0), in-place memory
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //find zero valued location
        int r = int(matrix.size());
        int c = int(matrix[0].size());
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < r; k++){
                        if(matrix[k][j] != 0) matrix[k][j] = dummy;
                    }
                    
                    for(int l = 0; l < c; l++){
                        if(matrix[i][l] != 0) matrix[i][l] = dummy;
                    }
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == dummy) matrix[i][j] = 0;
            }
        }
    }
};

//Time Complexity: O(M*N), Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //column check;
        int R = int(matrix.size());
        int C = int(matrix[0].size());
        bool isCol = false;
        for(int i = 0; i < R; i++){
            if(matrix[i][0] == 0){
                isCol = true;
            }
        }
        
        for(int i = 0; i < R; i++){
            for(int j = 1; j < C; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < C; i++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < R; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 0; i < R; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < C; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isCol){
            for(int i = 0; i < R; i++){
                matrix[i][0] = 0;
            }
        }
    }
};