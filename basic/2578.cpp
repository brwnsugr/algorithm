//acmicpc.net
//bingo 
#include <iostream>
#include <vector>
using namespace std;

#define N 5

int board[N][N];
int call[N*N+1];
vector<pair<int, int>> pos(N*N+1);

bool check_vertical(int y, int x){
    for(int i=0; i<N; i++)
        if(board[i][x] != -1)
            return false;
        return true;
}

bool check_horizonal(int y, int x){
    for(int i=0; i<N; i++)
        if(board[y][i]!= -1)
            return false;
        return true;
}

bool check_left_diagonal(){
    for(int i = 0; i<N; i++)
        if(board[i][i]!=-1)
            return false;
    return true;
}

bool check_right_diagonal(){
    for(int i=0; i<N; i++)
        if(board[i][N-i-1] != -1)
            return false;
    return true;
}

int main(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin>>board[i][j];
            pos[board[i][j]] = make_pair(i, j);
        }
    for(int i=1; i<=N*N; i++)
        cin>>call[i];
    int cnt = 0;
    int ret = 0;
    bool left_diagonal_completed = false;
    bool right_diagonal_completed = false;
    for(int i=1; i<=N*N; i++){
        int num = call[i];
        int y = pos[num].first;
        int x = pos[num].second;
        board[y][x] = -1;
        if(check_horizonal(y,x))
            cnt++;
        if(check_vertical(y,x))
            cnt++;
        if(y == x && !left_diagonal_completed && check_left_diagonal()){
            left_diagonal_completed = true;
            cnt++;
        }
        if(y==N-x-1&& !right_diagonal_completed && check_right_diagonal()){
            right_diagonal_completed = true;
            cnt++;
        }
        if(cnt>=3){
            ret = i;
            break;
        }
    }
    cout<<ret <<endl;
    return 0;
}