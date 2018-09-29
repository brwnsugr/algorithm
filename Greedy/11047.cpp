//acmicpc.net
//Greedy Algorithm
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a(10000);
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=n; i>=1; i--){
        ans += k/a[i];
        k %= a[i];
    }
    cout<<ans<<endl;
    return 0;
}