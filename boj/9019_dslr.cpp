#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T>0){
        int a, b;
        cin>>a>>b;
        vector<bool> visit(10001, false);
        vector<int> next(10001, 0);
        vector<char> traces(10001);
        vector<int> dist(10001,0);
        queue<int> q;
        visit[a] = true;
        q.push(a);
        while(!q.empty()){
            int here = q.front();
            if(here == b) break;
            q.pop();
            int there = 0;
            // D
            there = (here*2)%10000;
            if(!visit[there]){
                visit[there] = true;
                dist[there] = dist[here] + 1;
                next[there] = here;
                traces[there] = 'D';
                q.push(there);
            }
            // S
            if(here == 0){
                there = 9999;
            }
            if(here != 0){
                there = here-1;
            }
            if(!visit[there]){
                visit[there] = true;
                dist[there] = dist[here] + 1;
                next[there] = here;
                traces[there] = 'S';
                q.push(there);
            }
            // L
            there = (here%10)*10 + ((here/10)%10)*100 + ((here/100)%10)*1000 + here/1000;
            if(!visit[there]){
                visit[there] = true;
                dist[there] = dist[here] + 1;
                next[there] = here;
                traces[there] = 'L';
                q.push(there);
            }
            // R
            there = (here%10)*1000 + ((here/10)%10) + ((here/100)%10)*10 + ((here/1000)%10)*100;
            if(!visit[there]){
                visit[there] = true;
                dist[there] = dist[here] + 1;
                next[there] = here;
                traces[there] = 'R';
                q.push(there);
            }
        }
        string s;
        vector<char> tmp;
        while(true){
            tmp.push_back(traces[b]);
            b = next[b];
            if(b == a) break;
        }
        for(int i = tmp.size()-1; i >= 0; --i){
            s += tmp[i];
        }
        cout<<s<<endl;
        T--;
    }
    return 0;
}