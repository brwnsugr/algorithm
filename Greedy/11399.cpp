//acmicpc.net
//Greedy

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int sum = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        ans += sum;
    }
    cout<<ans<<endl;
    return 0;
 }