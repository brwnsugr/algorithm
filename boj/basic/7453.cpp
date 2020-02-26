//acmicpc.net
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v1;
vector<int> v2;

int main(){
    cin>>n;
    int idx = 0;
    int a[n],b[n],c[n],d[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v1.push_back(a[i]+b[j]);
            v2.push_back(c[i]+d[j]);
            idx++;
        }
    }
    sort(v1.begin(), v1.end());
    
    long long ans = 0;
    vector<int>::iterator it, it_2;
    for(int i=0; i<idx; i++){
        it = lower_bound(v1.begin(),v1.end(),-v2[i]);
        it_2 = upper_bound(v1.begin(),v1.end(),-v2[i]);
        while(it!=it_2){
            ans++;
            it++;
        }
    }
    cout<<ans<<endl;

    return 0;
}