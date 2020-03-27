#include <string>
#include <vector>
#include <iostream>

using namespace std;
const string d[] = {"A", "B", "C", "D", "E", "F"};
string base(int& n, int curr){
    string tmp;
    int r = 0;
    while(curr >= n){
        int q = curr/n;
        r = curr % n;
        string element;
        curr = q;
        if(r < 10) element = to_string(r);
        if(r >= 10)  element = d[r-10];
        tmp.insert(0,element);
    }
    string final;
    if(curr < 10) final = to_string(curr);
    if(curr >= 10) final = d[curr-10];
    tmp.insert(0,final);
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int len = 0;
    int number = 0;
    string num_sequence;
    while(len < m*t+p){
        string tmp;
        tmp = base(n, number);
        num_sequence += tmp;
        len += int(tmp.length());
        number++;
    }
    for(int i = 0; i < t; i++){
        answer += num_sequence[m*i + (p-1)];
    }
    return answer;
}