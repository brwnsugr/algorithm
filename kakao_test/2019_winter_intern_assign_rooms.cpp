#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> parent;
    for(long long i = 0; i < (long long)(room_number.size()); i++){
        bool flag = false;
        if(!parent.count((long long)(room_number[i]))){
            parent[room_number[i]] = room_number[i]+1;
            answer.push_back(room_number[i]);
            flag = true;
        }
        long long now = parent[room_number[i]];
        while(parent.count(now)){
            long long next = parent[now];
            if(parent.count(next)) parent[now] = parent[next];
            now = next;
        }
        if(!flag){
            answer.push_back(now);
            parent[now] = now + 1;
        }
    }
    return answer;
}