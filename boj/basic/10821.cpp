#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len = int(s.length());
    int cnt = 0;
    for(int i = 0; i < len; i++){
        //','를 발견하면 cnt 증가
        if(s[i] == ','){
            cnt++;
        }
    }
    cnt++;
    cout<<cnt;
    return 0;
}