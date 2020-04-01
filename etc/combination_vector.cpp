#include<iostream>
#include<vector>
#include<set>
using namespace std;

void print_vector(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void pick(int n, vector<int>& picked, int to_pick){
    if(to_pick == 0){
        print_vector(picked);
    }
    int smallest = picked.empty() ? 1 : picked.back()+1;
    for(int next = smallest; next <= n; next++){
        picked.push_back(next);
        pick(n, picked, to_pick-1);
        picked.pop_back();
    }
}

int main(){
    vector<int> picked;
//    pick(5, picked, 2);
    return 0;
}