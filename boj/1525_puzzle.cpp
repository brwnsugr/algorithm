#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int main(){
    int dy[] = {-1,1,0,0};
    int dx[] = {0,0,-1,1};
    queue<int> q;
    unordered_map<int, int> d;
    int start = 0;
    for(int i = 0; i < 9; i++){
        int element; cin>>element;
        if(element == 0){
            element = 9;
        }
        start = start * 10  + element;
    }
    d[start] = 0;
    q.push(start);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        string num = to_string(here);
        int z = num.find('9');
        int x = z%3;
        int y = z/3;
        for(int i = 0; i < 4; i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if(next_y >= 0 && next_y < 3
               && next_x >= 0 && next_x < 3){
                string next = num;
                swap(next[x+y*3], next[next_x+next_y*3]);
                int there = stoi(next);
                if(d.count(there)==0){
                    d[there] = d[here] +1;
                    q.push(there);
                }
            }
        }
    }
    if(d.count(123456789) == 0){
        cout<< -1<<endl;
        return 0;
    }
    cout<<d[123456789]<<endl;
    return 0;
}