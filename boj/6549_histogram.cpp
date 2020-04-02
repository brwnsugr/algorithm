#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    
    while(1){
        int N; cin>>N;
        if(N == 0) break;
        long long answer = 0;
        vector<long long> histogram;
        for(int i = 0; i < N; i++){
            long long element; cin>>element;
            histogram.push_back(element);
        }
        histogram.push_back(0);
        stack<long long> remain;
        for(int i = 0 ; i < histogram.size(); i++){
            while(!remain.empty() && histogram[remain.top()] >= histogram[i]){
                int j = remain.top();
                long long height = histogram[j];
                remain.pop();
                int left = 0; int right = 0; int width = 0;
                if(remain.empty()){
                    left = 0;
                    right = i;
                }
                else{
                    left = remain.top() + 1;
                    right = i;
                }
                width = right - left;
                answer = max(answer, height * width);
            }
            remain.push(i);
        }
        cout<<answer<<endl;
    }
    return 0;
}