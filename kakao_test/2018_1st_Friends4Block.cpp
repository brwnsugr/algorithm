#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> convert_board(vector<string>& board){
    vector<string> converted_board;
    int height = board.size();
    int width = board[0].size();
    for(int i = 0; i < width; ++i){
        string tmp;
        for(int j = height-1; j >= 0; --j){
            tmp += board[j][i];
        }
        converted_board.push_back(tmp);
    }
    return converted_board;
}

void remove_block(int& height, int& width, vector<string>& board, int& cnt){
    vector<string> tmp;
    set<pair<int,int>> s;
    for(int i = 0; i < width-1; ++i){
        for(int j = 0; j < height-1; ++j){
            if(board[i][j] != ' '){
                if(board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1]){
                    s.insert(make_pair(i,j)); s.insert(make_pair(i+1,j)); s.insert(make_pair(i,j+1)); s.insert(make_pair(i+1,j+1));
                }
            }
        }
    }
    if(s.size()==0) return;
    for(auto it = s.begin(); it != s.end(); ++it){
        board[it->first][it->second] = ' ';
    }
    cnt += s.size();
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            if(board[i][j] == ' '){
                continue;
            }
            for(int k = j; k - 1 >= 0 && board[i][k-1]==' '; k--){
                swap(board[i][k], board[i][k-1]);
            }
        }
    }
    remove_block(height, width, board, cnt);
    return;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    board = convert_board(board);
    remove_block(m, n, board, answer);
    return answer;
}