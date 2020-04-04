// sol1 : using binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    vector<int> numbers;
    cin>>N;
    for(int i = 0; i < N; i++){
        int element; scanf("%d",&element);
        numbers.push_back(element);
    }
    sort(numbers.begin(), numbers.end());
    cin>>M;
    for(int i = 0; i < M; i++){
        int num; scanf("%d", &num);
        if(binary_search(numbers.begin(), numbers.end(), num)) printf("1\n");
        else cout<<0<<'\n';
    }
    return 0;
}

//sol2 : using unordered_map 

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int N, M;
    unordered_map<int, int> m;
    vector<int> numbers;
    cin>>N;
    for(int i = 0; i < N; i++){
        int element; scanf("%d",&element);
        m[element]++;
    }
    cin>>M;
    for(int i = 0; i < M; i++){
        int num; scanf("%d", &num);
        if(m.count(num) > 0){
            printf("1\n");
        } else{
            printf("0\n");
        }
    }
    return 0;
}