//acmicpc.net
//Print Permutation by given integer, N (Brute Force)
#include <iostream>
#include <vector>
using namespace std;

int N ;
vector<bool> visit;

void print_vector(vector<int>& v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}
void recursive(vector<int>& v) {
    if(v.size() == N) {
        print_vector(v);
    }
    for(int i=1; i<=N; i++) {
        if(!visit[i]) {
            v.push_back(i);
            visit[i] = true;
            recursive(v);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N;
    visit.resize(N+1, false);
    vector<int> temp;
    recursive(temp);
    return 0;
}