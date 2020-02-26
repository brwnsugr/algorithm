//acmicpc.net
//sorting the Location 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int main(){
    scanf("%d",&n);
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        cin>>a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i=0; i<n; i++){
        cout<<a[i].first<<" "<<a[i].second<<'\n';
    }
    return 0;
}