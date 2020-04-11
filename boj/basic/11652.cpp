#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<long long, int> check;
    pair<long long, int> answer_pair = make_pair(0,0);
    int T;
    scanf("%d", &T);
    long long a;
    while(T--){
        scanf("%lld", &a);
        check[a]++;
    }

    for(auto it = check.begin(); it!= check.end(); it++){
        if(it->second > answer_pair.second) answer_pair = make_pair(it->first, it->second);
        else if(it->second == answer_pair.second && it->first < answer_pair.first){
            answer_pair = make_pair(it->first, it->second);
        }
    }
    cout<<answer_pair.first<<endl;
    return 0;
}