#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int answer = 0;
    vector<int> numbers;
    vector<char> operations;
    string s = "";
    cin>>s;
    int arith_idx = -1;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '+' || s[i] == '-'){
            operations.push_back(s[i]);
            string str_num = s.substr(arith_idx+1, i-arith_idx-1);
            int number = atoi(str_num.c_str()); numbers.push_back(number);
            arith_idx = i;
        }
    }
    //final_arith_idx에서 마지막 숫자 받기
    string final_str_num = s.substr(arith_idx+1, s.length()-arith_idx-1);
    int number = atoi(final_str_num.c_str());
    numbers.push_back(number);
    
    //operation 벡터를 순회하면서 - 가 나오고, 그 다음 바로 +가 나오는 경우('-' 바로 다음 나오는 '+' 가 있는 operations의 인덱스를 i라 하자.)
    //(연속으로 나오는 '+' 의 횟수 + 1)횟수만큼의 숫자들을 모두 더해주자. 이 숫자들의 idx는 i ~ i+('+'가 연속으로 나오는 횟수임)
    answer += numbers[0];
    for(int i = 0; i < operations.size(); i++){
        if(operations[i] == '+'){
            answer += numbers[i+1];
        }
        if(operations[i] == '-'){
            if(i+1 < operations.size() && operations[i+1] == '+'){
                int count = 0;
                int start = i+1;
                i++; count++;
                while(i+1 < operations.size() && operations[i+1] =='+'){
                    i++; count++;
                }
                int minus_sum = numbers[start];
                for(int j = start; j <= i; j++){
                    minus_sum += numbers[j+1];
                }
                answer -= minus_sum;
            }
            else if(i+1 < operations.size() && operations[i+1] == '-'){
                answer -= numbers[i+1];
            }
            else{
                answer -= numbers[i+1];
            }
        }
    }
    cout<<answer;
    return 0;
}