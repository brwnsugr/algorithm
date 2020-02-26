//acmicpc.net
//Conversion of Numeral System
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    int ans = 0;
    string s;
    int b;
    cin >> s >> b;
    reverse(s.begin(),s.end());
    for (int i=0; i<s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            ans += (s[i]-'0')*pow(b,i);
        } else {
            ans += (s[i]-'A'+10)*pow(b,i);
        }
    }
    cout << ans << '\n';
    return 0;
}