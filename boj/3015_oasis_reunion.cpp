#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    vector<int> a;
    long long answer = 0;
    int N; cin>>N;
    for(int i = 0; i < N; i++){
        int element; cin>>element;
        a.push_back(element);
    }
    stack<pair<int,int>> s;
    for(int i = 0; i < a.size(); i++){
        pair<int, int> p = make_pair(a[i], 1);
        while(!s.empty()){
            if(s.top().first <= a[i]){
                answer += (long long)s.top().second;
                if(s.top().first == a[i]){
                    p.second += s.top().second;
                }
                s.pop();
            } else{
                break;
            }
        }
        if(!s.empty()) answer += 1;
        s.push(p);
    }
    cout<<answer<<endl;
    return 0;
}