#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visit[200001][2];
int main(){
    int C, B;
    cin>>C>>B;
    int time = 0;
    memset(visit, false, sizeof(visit));
    queue<pair<int,int>> q;
    q.push(make_pair(B,0));
    //코니가 t초 후 p위치에 도착했을 때 브라운이 p 위치에 t-2k에 도착했는지 여부 찾기
    bool flag = false;
    while(1){
        C += time;
        if(C > 200000){
            flag = true;
            break;
        }
        if(visit[C][time%2]){
            break;
        }
        for(int i = 0, size = q.size(); i < size; i++){
            pair<int,int> here = q.front();
            int new_time = (here.second+1)%2;
            q.pop();
            int there = here.first-1;
            if(there >= 0 && !visit[there][new_time]){
                visit[there][new_time] = true;
                q.push(make_pair(there, new_time));
            }
            there = here.first+1;
            if(there <= 200000 && !visit[there][new_time]){
                visit[there][new_time] = true;
                q.push(make_pair(there,new_time));
            }
            there = here.first*2;
            if(there <= 200000 && !visit[there][new_time]){
                visit[there][new_time] = true;
                q.push(make_pair(there, new_time));
            }
        }
        time += 1;
    }
    
    if(flag){
        cout<<-1<<endl;
    }
    else{
        cout<<time<<endl;
    }
    return 0;
}