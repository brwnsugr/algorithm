#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
vector<vector<int>> countries;
bool visit[51][51];
int dy[] = {-1, 1, 0 ,0};
int dx[] = {0, 0, -1, 1};
int sum = 0;
vector<pair<int,int>> pos;
int L, R;

void move(pair<int, int> now, vector<vector<int>>& board, int N){
    visit[now.first][now.second] = true;
    for(int k = 0; k < 4; k++){
        int next_y = now.first + dy[k];
        int next_x = now.second + dx[k];
        if(next_y >= 0 && next_y < N
            &&next_x >= 0 && next_x < N
            && !visit[next_y][next_x]
            && abs(board[next_y][next_x]-board[now.first][now.second]) >= L
            && abs(board[next_y][next_x]-board[now.first][now.second]) <= R){
            pos.push_back(make_pair(next_y, next_x));
            move(make_pair(next_y,next_x), board, N);
        }
    }
    return;
}

int main(){
    int N;
    cin>>N>>L>>R;
    int answer= 0;
    countries.resize(N,vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>countries[i][j];
        }
    }
    
    while(true){
        int mov_cnt = 0;
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++) {
                if(visit[i][j]) continue;
                pos.clear();
                sum = countries[i][j];
                pos.push_back(make_pair(i,j));
                move(make_pair(i,j), countries, N);
                if(pos.size() == 1) continue;
                mov_cnt++;
                for(int i = 1; i < pos.size(); i++){
                    sum += countries[pos[i].first][pos[i].second];
                }
                int avg = sum / pos.size();
                for(int i = 0; i < pos.size(); i++){
                    countries[pos[i].first][pos[i].second] = avg;
                }
            }
        }
        if(mov_cnt == 0) break;
        answer++;
    }
    cout<<answer<<endl;
    return 0;
}