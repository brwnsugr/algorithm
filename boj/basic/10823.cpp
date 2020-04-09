#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    string s;
    string line;
    while(cin>>line){
        s += line;
    }
    
    istringstream sin(s);
    string tmp;
    int sum = 0;
    while(getline(sin, tmp, ',')){
        int num = stoi(tmp);
        sum += num;
    }
    cout<<sum<<endl;
    return 0;
}