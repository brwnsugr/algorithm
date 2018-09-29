//acmicpc.net
//Conversion of Numeral System 
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,b,r;
    string ans = "";
    cin>>n>>b;
    while(n>0){
        r = n % b;
        if(r<10){
            ans += char(r+'0');
        }
        else {
            ans += char(r-10 + 'A');
        }
        n /= b;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
    return 0;
}