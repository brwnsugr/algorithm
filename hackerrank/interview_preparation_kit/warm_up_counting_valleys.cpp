using namespace std;

int countingValleys(int n, string s) {
    // isInValley flag 를 도입하여 valley 에 진입하면 true, 기본은 false,
    // 0 미만인 상황이고 valley 진입 시  flag 를 false -> true
    // 0 미만으로 진입하면 count++ -> true 면서 altitude 0으로 다시 올라오는 순간 flag = false
    // 다시 0 미만으로 진입하고, flag = false 인 상황이면 flag 를 false -> true로 변경함
    int count = 0;
    int altitude = 0;
    bool isInValley = false;
    for(int i = 0; i < int(s.length()); i++){
        if(s[i] == 'U') altitude++;
        if(s[i] == 'D') altitude--;
        if(!isInValley && altitude < 0){
            isInValley = true;
            count++;
            continue;
        }
        if(isInValley && altitude >= 0) isInValley = false;
    }
    return count;
}