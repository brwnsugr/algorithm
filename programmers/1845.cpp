int solution(vector<int> nums)
{
    unordered_map<int, int> m;
    int answer = 0;
    for(int i = 0; i < nums.size(); ++i){
        m[nums[i]]++;
    }
    if(m.size() < nums.size()/2){
        answer = m.size();
    }
    else{
        answer = nums.size()/2;
    }
    return answer;
}