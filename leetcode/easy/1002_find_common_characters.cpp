class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> answer;
        vector<string> tmp;
        unordered_map<string, int> m;
        unordered_map<string, int> compare;
        for(int i = 0; i < A.size(); i++){
            compare.clear();
            for(int j = 0; j < A[i].length(); j++){
                if(i==0){
                    string now(1,A[i][j]);
                    m[now]++;
                }
                else{
                    string now(1, A[i][j]);
                    compare[now]++;
                }
            }
            if(i > 0){
                for(auto it = m.begin(); it != m.end(); ++it){
                    if (compare[it->first] <= it->second){
                        if(compare[it->first] == 0){
                            it->second = 0;
                        } else{
                            it->second = compare[it->first];
                        }
                    }
                    else if(compare[it->first] > it->second){
                        continue;
                    }
                }
            }
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second > 0){
                for(int i= 0; i < it->second; i++){
                    answer.push_back(it->first);
                }
            }
        }
        sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++){
            cout<<answer[i]<<" ";
        }
        return answer;
    }
};