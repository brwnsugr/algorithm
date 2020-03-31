#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<string> s;
int main(){
    int n; cin>>n;
    //enter -> set에 넣기
    //leave -> set에서 빼기
    while(n--){
        string person, what;
        cin>>person>>what;
        if(what == "enter"){
            s.insert(person);
        }
        else{
            s.erase(s.find(person));
        }
    }
    for(auto it = s.rbegin(); it != s.rend(); ++it){
        cout<<*it<<'\n';
    }
    return 0;
}