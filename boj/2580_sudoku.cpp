#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> board;
vector<vector<bool>> c1; // row 체크 c1[i][element] = true; i번째 row에 , element 값은 이미 있음
vector<vector<bool>> c2; // col 체크 c2[element][j] = true; j번째 col에 , i값은 이미 있음
vector<vector<bool>> c3; // small square 체크 c3[i][j] = i번째 square에 j값은 이미 있음

int square(int row, int col){
    int y = row/3;
    int x = col/3;
    return (y*3)+x;
}

void go(int row, int col, int cnt){
    if(cnt == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        exit(0);
    }
    if(board[row][col] != 0){
        if(col == 8) go(row+1, 0, cnt+1);
        else go(row, col+1, cnt+1);
    } else{
        for(int i = 1; i <= 9; i++){
            if(!c1[row][i] && !c2[i][col] && !c3[square(row, col)][i]){
                c1[row][i] = c2[i][col] = c3[square(row,col)][i] = true;
                board[row][col] = i;
                if(col==8) go(row+1, 0, cnt+1);
                else go(row, col+1, cnt+1);
                c1[row][i] = c2[i][col] = c3[square(row,col)][i] = false;
                board[row][col] = 0;
            }
        }
    }
}

int main(){
    board.resize(9, vector<int>(9,0));
    c1.resize(10, vector<bool>(10, false));
    c2.resize(10, vector<bool>(10, false));
    c3.resize(10, vector<bool>(10, false));
    vector<pair<int,int>> zeros;
    for(int i = 0; i < 9; i++){ // i'th row
        for(int j = 0; j < 9; j++){ // j'th col
            int element; cin>>element;
            board[i][j] = element;
            if(element == 0) continue;
            else{
                //c1 marking
                c1[i][element] = true;
                //c2 marking
                c2[element][j] = true;
                //c3 marking
                c3[square(i,j)][element] = true;
            }
        }
    }
    go(0,0,0);
    return 0;
}