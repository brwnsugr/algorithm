#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    string s;
    int lower_case, upper_case, blank, numbers;
    while(getline(cin, s)){
        lower_case = upper_case = blank = numbers = 0;
        for(int i = 0; i < int(s.length()); i++){
            if(isdigit(s[i])){
                numbers++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                lower_case++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                upper_case++;
            }
            else{
                blank++;
            }
        }
        cout<<lower_case<<' '<<upper_case<<' '<<numbers<<' '<<blank<<'\n';
    }
    return 0;
}