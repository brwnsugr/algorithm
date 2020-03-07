#include <string>
#include <vector>

using namespace std;
int getStartTime(int &endTime, string &line){
    int startTime = 0;
    string tmp = line.substr(24); tmp.pop_back();
    int elapsedTime = stod(tmp.c_str())*1000;
    startTime = endTime - elapsedTime + 1;
    return startTime;
}

int getEndTime(string &tmp){
    int endTime = 0;
    int hours = atoi(tmp.substr(0,2).c_str())*60*60*1000;
    int minutes = atoi(tmp.substr(3,2).c_str())*60*1000;
    int seconds = atoi(tmp.substr(6,2).c_str())*1000;
    int milliseconds = atoi(tmp.substr(9,3).c_str());
    endTime = hours + minutes + seconds + milliseconds;
    return endTime;
}

vector<pair<int,int>> timeParse(vector<string> &lines){
    vector<pair<int,int>> times;
    for(int i = 0; i < lines.size(); ++i){
        string tmp = lines[i].substr(11,12);
        int endTime = getEndTime(tmp);
        int startTime = getStartTime(endTime, lines[i]);
        times.push_back(make_pair(startTime, endTime));
    }
    return times;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> times = timeParse(lines);
    for(int i = 0; i < times.size(); i++){
        int rangeStart = times[i].second - 1;
        int rangeEnd = rangeStart + 1000;
        int count = 0;
        for(int j = 0; j < times.size(); ++j){
            if(times[j].first <= rangeEnd && times[j].second >= rangeStart){
                count++;
            }
        }
        if(count > answer) answer = count;
    }
    return answer;
}