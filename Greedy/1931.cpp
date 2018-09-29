//acmicpc.net
//Booking a Meeting Room(Greedy)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct memory{
    int begin, end;
};

bool cmp(const memory &u, const memory &v){
    if(u.end==v.end){
        return u.begin < v.begin;
    }
    else{
        return u.end<v.end;
    }
};

int main(){
    int n;
    cin>>n;
    vector<memory> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].begin>>a[i].end;
    }
    sort(a.begin(),a.end(),cmp);
    int now = 0;
    int ans = 0;
    for(int i=0; i<n;i++){
        if(now<=a[i].begin){
            now = a[i].end;
            ans +=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}