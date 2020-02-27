#include <algorithm>
#include <vector>
#include <iostream>
// www.acmicpc.net/problem/6603
// Brute Force using prev_permutation algorithm library
using namespace std;
void print_vector(vector<int> &numbers){
    for(int i = 0; i < numbers.size(); i++){
        cout<< numbers[i] << " ";
    }
    cout<<endl;
}

void permutation(vector<int> &order, vector<int> &lotto_set){
    do{
        vector<int> comb;
        for(int i = 0; i < order.size(); i++){
            if(order[i]==1) comb.push_back(lotto_set[i]);
        }
        print_vector(comb);
    }while(prev_permutation(order.begin(), order.end()));
}

int main(){
    while(true){
        vector<int> order;
        int N;
        cin>>N;
        if( N == 0) return 0;
        else{
            int one = 6;
            int zero = N-one;
            vector<int> lotto_set;
            for(int i = 0; i < N; i++){
                int element;
                cin>>element;
                lotto_set.push_back(element);
            }
            for(int k = 0; k < 6; k++){
                order.push_back(1);
            }
            for(int j = 0; j < zero; j++){
                order.push_back(0);
            }
            permutation(order, lotto_set);
            cout<<endl;
        }
    }
    return 0;
}