class Solution {
public:
    int romanToInt(string s) {
        make_roman();
        int answer = 0;
        if(s.length()==1){
            answer += m[s[0]];
            return answer;
        }
        for(int i = 1; i <= s.length(); i++){
            if(s[i-1]=='I'){
                if(s[i]=='X'){
                    answer += 9;
                    i+=1;
                }
                else if(s[i] == 'V'){
                    answer += 4;
                    i+=1;
                }
                else{
                    answer += m[s[i-1]];
                }
            }
            else if(s[i-1]=='X'){
                if(s[i]=='C'){
                    answer += 90;
                    i+=1;
                }
                else if(s[i] == 'L'){
                    answer += 40;
                    i+=1;
                }
                else{
                    answer += m[s[i-1]];
                }
            }
            else if(s[i-1]=='C'){
                if(s[i]=='M'){
                    answer += 900;
                    i+=1;
                }
                else if(s[i] == 'D'){
                    answer += 400;
                    i+=1;
                }
                else{
                    answer += m[s[i-1]];
                }
            }
            else{
                answer += m[s[i-1]];
            }
        }
        return answer;
    }
private:
    unordered_map<char, int> m;
    void make_roman(){
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
    }
};