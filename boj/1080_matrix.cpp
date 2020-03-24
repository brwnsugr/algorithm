#include<vector>
#include<iostream>
using namespace std;
void flip(vector<vector<int>>& board, int& y, int& x){
    for(int i = y; i < y+3; i++){
        for(int j = x; j < x+3; j++){
            board[i][j] = board[i][j] == 1 ? 0 : 1;
        }
    }
}
int main(){
    int N, M;
    int answer = 0;
    cin>>N>>M;
    vector<vector<int>> original(N, vector<int>(M,0));
    vector<vector<int>> mirror(N, vector<int>(M,0));
    
    for(int i = 0; i < N; i++){
        string tmp; cin>>tmp;
        for(int j = 0; j < M; j++){
            int element = tmp[j]-'0';
            original[i][j] = element;
        }
    }
    
    for(int i = 0; i < N; i++){
        string tmp; cin>>tmp;
        for(int j = 0; j < M; j++){
            int element = tmp[j]-'0';
            mirror[i][j] = element;
        }
    }
    
    for(int i = 0; i < N-2; i++){
        for(int j = 0; j < M-2; j++){
            if(original[i][j] != mirror[i][j]){
                answer++;
                flip(original, i, j);
            }
        }
    }
    
    //Sanity Check
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(original[i][j] != mirror[i][j]){
                cout<<-1; return 0;
            }
        }
    }
    cout<<answer;
    return 0;
}