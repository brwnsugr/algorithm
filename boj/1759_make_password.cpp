#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

vector<char> password_list;
set<string> ans_set;
string collection_set = "aieou";
int L,C;
void comb(string s, int consonant, int collection, int count){
    
    if(count == L){
        if(consonant >= 2 && collection >= 1){
            ans_set.insert(s);
        }
        return;
    }
    else{
        for(int i = 0; i < C; ++i){
            if(s.find(password_list[i]) == string::npos){
                if(collection_set.find(password_list[i]) != string::npos ){ // 모음인 경우
                    if(s.back()-'a' < password_list[i]-'a'){
                        comb(s+password_list[i], consonant, collection+1, count+1);
                    }
                }
                else{
                    if(s.back()-'a' < password_list[i]-'a'){
                        comb(s+password_list[i], consonant+1, collection, count+1);
                    }
                }
            }
        }
    }
}

int main(){
    cin>>L>>C;
    for(int i = 0; i < C; ++i){
        char element; cin>>element;
        password_list.push_back(element);
    }
    sort(password_list.begin(), password_list.end());
    string s ="";
    comb(s, 0, 0, 0);
    for(auto it = ans_set.begin(); it != ans_set.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}