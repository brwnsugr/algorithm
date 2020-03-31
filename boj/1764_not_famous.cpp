#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<string> s;
set<string> ans;
int main(){
    int N, M;
    cin>>N>>M;
    while(N--){
        string name;
        cin>>name;
        s.insert(name);
    }
    while(M--){
        string name;
        cin>>name;
        auto it = s.find(name);
        if(it != s.end()){
            ans.insert(name);
            s.erase(s.find(name));
        }
    }
    cout<<ans.size()<<endl;
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}