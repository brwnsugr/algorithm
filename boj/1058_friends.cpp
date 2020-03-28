#include <cstring>
#include <string>
#include <vector>
#include<iostream>
#include <queue>

using namespace std;
bool board[51][51];
bool check[51];
int dim[51];
int main(){
    int N; cin>>N;
    int answer = 0;
    for(int i = 0; i < N; i++){
        string tmp; cin>>tmp;
        for(int j = 0; j < int(tmp.length()); j++){
            if(tmp[j] == 'Y') board[i][j] = true;
            if(tmp[j] == 'N') board[i][j] = false;
        }
    }
    memset(dim, 0, sizeof(dim));
    for(int i = 0; i < N; i++){
        memset(check, 0, sizeof(check));
        queue<pair<int,int>> q;
        q.push(make_pair(i,0));
        check[i]=true;
        while(!q.empty()){
            pair<int,int> here = q.front();
            q.pop();
            if(here.second == 2) break;
            for(int j = 0; j < N; j++){
                if(!check[j] && board[here.first][j]){
                    dim[i] += 1; check[j] = true;
                    q.push(make_pair(j,here.second+1));
                }
            }
        }
        answer = max(dim[i], answer);
    }
    cout<<answer<<endl;
    return 0;
}