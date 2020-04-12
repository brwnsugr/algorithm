#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    int ans = 0;
    cin>>n;
    vector<pair<int,int>> a;
    a.reserve(n);
    for(int i = 0; i < n; i++){
        int element; scanf("%d", &element);
        a.push_back(make_pair(element, i));
    }
    sort(a.begin(), a.end());
    // 같은 원소가 나왔을 때, idx 차이의 최대값이 곧 bubble sort Stage Level 임
    for(int i = 0; i < n; i++){
        if( a[i].second - i > ans) ans = a[i].second - i;
    }
    cout<<ans+1<<'\n';
    return 0;
}