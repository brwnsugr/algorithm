#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    vector<string> nums;
    nums.reserve(4);
    while(getline(cin, s, ' ')){
        nums.push_back(s);
    }
    string a_b = nums[0]+nums[1];
    string c_d = nums[2]+nums[3];
    long long ab = stoll(a_b);
    long long cd = stoll(c_d);
    cout<<ab+cd<<endl;
    return 0;
}