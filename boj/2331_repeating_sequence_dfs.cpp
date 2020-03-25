#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
unordered_map<int, pair<int,int>> check;
int dup_num = 0;
int dfs(int& n, int& P, int idx){
    if(check[n].first > 0){
        dup_num = n;
    }
    else{
        check[n].first++;
        check[n].second = idx;
        int next = 0;
        while(n > 0){
            int digit = n%10;
            next += pow(digit, P);
            n /= 10;
        }
        dfs(next, P, idx+1);
    }
    return dup_num;
}

int main(){
    int A, P;

    cin>>A>>P;
    int num = dfs(A, P, 0);
    
    cout<<check[num].second;
    return 0;
}