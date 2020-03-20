#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> board;
int ans = 0;

bool check(int row, int col, int N){
    bool flag = true;
    for(int i = 0; i < N; i++){
        if (i==row) continue;
        if(board[i][col]){
            return false;
        }
    }
    //위 오른쪽 대각선 체크
    int next_y = row-1;
    int next_x = col+1;
    while(next_y >= 0 && next_x <N){
        if(board[next_y][next_x]){
            return false;
        }
        next_y--;
        next_x++;
    }
    //위 왼쪽 대각선 체크
    next_y = row-1;
    next_x = col-1;
    while(next_y >= 0 && next_x >= 0){
        if(board[next_y][next_x]){
            return false;
        }
        next_y--;
        next_x--;
    }
    return flag;
}

void calc(int row, int count, int N){
    if(row == N){
        ans++;
        return;
    }
    for(int col = 0; col < N; col++){
        board[row][col] = true;
        if(check(row, col, N)){
            calc(row+1, count+1, N);
        }
        board[row][col] = false;
    }
}

int main(){
    int N;
    cin>>N;
    board.resize(N,vector<bool>(N,false));
    calc(0,0,N);
    cout<<ans;
    return 0;
}