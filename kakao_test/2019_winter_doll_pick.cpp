#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;
    int R = int(board.size());
    for(int i = 0; i < moves.size(); i++){
        int pos = moves[i]-1;
        for(int j = 0; j < R; j++){
            if(board[j][pos] == 0) continue;
            else{
                int curr = board[j][pos];
                board[j][pos] = 0;
                if(bucket.empty()){
                    bucket.push(curr); break;
                }
                else{
                    if(bucket.top() == curr){
                        answer += 2; bucket.pop(); break;
                    }
                    else{
                        bucket.push(curr); break;
                    }
                }
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> boards1 = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves1 = {1,5,3,5,1,2,1,4};
    cout<<solution(boards1, moves1);
    return 0;
}