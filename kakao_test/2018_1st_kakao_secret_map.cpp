#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> binary_convert(int& n, int num){
    vector<int> binary_set;
    while(true){
        binary_set.push_back(num%2);
        num /= 2;
        if(num == 0) break;
    }
    if(binary_set.size() < n){
        int size = binary_set.size();
        for(int i = 0; i < n - size; ++i){
            binary_set.push_back(0);
        }
    }
    reverse(binary_set.begin(), binary_set.end());
    return binary_set;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> binary_arr1;
    vector<vector<int>> binary_arr2;
    for(int i = 0; i < n; ++i){
        binary_arr1.push_back(binary_convert(n,arr1[i]));
        binary_arr2.push_back(binary_convert(n,arr2[i]));
    }
    
    for(int i = 0; i < n; ++i){
        string tmp;
        for(int j = 0; j < n; ++j){
            if(binary_arr1[i][j] == 0 && binary_arr2[i][j] == 0){ // No exists a wall. 
                tmp += " ";
            }
            else{ // when these exists a wall. 
                tmp += "#";
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}