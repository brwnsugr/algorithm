#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
using namespace std;
set<int> candidates;
unordered_map<char, int> m;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int R, C;
int ans = 1;
vector<vector<char>> board;
vector<bool> check;

void traverse(int y, int x, int cnt){
    if(cnt > ans){
        ans = cnt;
    }
    for(int i = 0; i < 4; i++){
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(next_y >= 0 && next_y < R &&
           next_x >= 0 && next_x < C ){
            char next_char = board[next_y][next_x];
            if(check[next_char-'A'] == false){
                check[next_char-'A'] = true;
                traverse(next_y,next_x, cnt+1);
                check[next_char-'A'] = false;
            }
        }
    }
    return;
}

int main(){
    cin>>R>>C;
    board.resize(R,vector<char>(C,0));
    check.resize(26,false);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            char element; cin>>element;
            board[i][j] = element;
        }
    }
    check[board[0][0]-'A'] = true;
    traverse(0,0,1);
    cout<<ans<<endl;
    return 0;
}