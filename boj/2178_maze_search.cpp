#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    int N, M;
    int board[100][100];
    int dist[100][100];
    cin>>N>>M;
    for(int i = 0; i < N; i++){
        string s; cin>>s;
        for(int j = 0; j < M; j++){
            board[i][j] = s[j]-'0';
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    while(!q.empty()){
        pair<int, int> here = q.front();
        if(here.first == N-1 && here.second == M-1){
            break;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_y = here.first + dy[i];
            int next_x = here.second + dx[i];
            if(next_y >= 0 && next_y < N
               && next_x >= 0 && next_x < M
               && board[next_y][next_x] == 1){
                board[next_y][next_x] = 0;
                dist[next_y][next_x] = dist[here.first][here.second] + 1;
                q.push(make_pair(next_y, next_x));
            }
        }
    }
    cout<<dist[N-1][M-1]<<endl;
    return 0;
}