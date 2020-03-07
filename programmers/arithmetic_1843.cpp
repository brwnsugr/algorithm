#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    int answer = 1;
    int nums = arr.size()/2 + 1;
    
    vector<vector<int>> dp_max(101, vector<int>(101,-100000));
    vector<vector<int>> dp_min(101, vector<int>(101, 100000));
    
    for(int i = 0; i < nums; ++i){
        dp_max[i][i] = atoi(arr[i*2].c_str());
        dp_min[i][i] = atoi(arr[i*2].c_str());
    }
    
    for(int calc=1; calc < nums; ++calc){
        for(int i = 0; i < nums-calc; i++){
            int j = i + calc;
            for(int k = i ; k < j; k++){
                if(arr[k*2 + 1] == "-"){
                    dp_max[i][j] = max(dp_max[i][k] - dp_min[k+1][j], dp_max[i][j]);
                    dp_min[i][j] = min(dp_min[i][k] - dp_min[k+1][j], dp_min[i][j]);
                }
                else if(arr[k*2 +1] == "+"){
                    dp_max[i][j] = max(dp_max[i][k] + dp_max[k+1][j], dp_max[i][j]);
                    dp_min[i][j] = min(dp_min[i][k] + dp_min[k+1][j], dp_min[i][j]);
                }
            }
        }
    }
    answer = dp_max[0][nums-1];
    return answer;
}