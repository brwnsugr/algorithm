#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(const char& a, const char& b){
    return a > b;
}

int main(){
    vector<int> num;
    int check = 0;
    int zeros = 0;
    string s;
    cin>>s;
    for(int i = 0; i < s.length(); i++){
        if(s[i]-'0' == 0) zeros++;
        check += s[i]-'0';
    }
    
    if(zeros == 0 || check % 3 != 0){ // Exception Case.
        cout<<-1; return 0;
    }
    
    sort(s.begin(), s.end(), compare);
    cout<<s;

    return 0;
}
