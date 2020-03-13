#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> convert_to_minutes(vector<string> &timetable){
    vector<int> res;
    for(size_t i = 0; i < timetable.size(); ++i){
        int hours = stoi(timetable[i].substr(0,2));
        int minutes = stoi(timetable[i].substr(3,2));
        int total_minutes = (hours*60) + minutes;
        if(total_minutes == 1440){
            res.push_back(1440);
            continue;
        }
        total_minutes %= 1439;
        if(total_minutes != 0) res.push_back(total_minutes);
    }
    return res;
}

string time_revert(int& total_minutes){
    int int_hour = total_minutes / 60;
    int int_minutes = total_minutes % 60;
    string hour = to_string(int_hour);
    if(hour.size()==1) hour = "0"+hour;
    string minutes = to_string(int_minutes);
    if (minutes.size()==1) minutes = "0"+minutes;
    string reverted_time = hour + ":" + minutes;
    return reverted_time;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int start_time = 540;
    vector<int> converted_table = convert_to_minutes(timetable);
    int remains = converted_table.size();
    sort(converted_table.begin(), converted_table.end());
    int tmp = 2;
    int count = 0;
    for(int i = start_time; count < n; i+=t){
        for(int j = 0; j < m; ++j){
            int onboard_members = 0;
            if(count == n-1 && j == m - 1){ // 막차인 경우
                int last_time = 10000;
                for(int k = 0; k < converted_table.size(); ++k){
                    if(converted_table[k] <= i){
                        last_time = min(last_time, converted_table[k]);
                    }
                }
                if(last_time < 10000){
                    tmp = last_time - 1;
                    break;
                }
                else{
                    tmp = i;
                    break;
                }
            }
            if(!converted_table.empty() && converted_table[0] <= i){
                converted_table.erase(converted_table.begin());
                onboard_members++;
            }
        }
        count++;
    }
    string answer = time_revert(tmp);
    return answer;
}