//acmicpc.net
#include <iostream>
using namespace std;

long long d[90];

int main() {
    int n;
    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for (int i=3; i<=n; i++) {
        d[i] = d[i-1] + d[i-2];
        }
    cout<<d[n]<<'\n';
    return 0;
}