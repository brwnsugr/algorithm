#include <iostream>
#include <algorithm>
#include <vector>
int main(){
    int T; scanf("%d", &T);
    std::vector<int> cnt(10001, 0);
    int a;
    while(T--){
        scanf("%d", &a);
        cnt[a]++;
    }
    for(int i = 1; i <= 10000; i++){
        while(cnt[i]>0){
            printf("%d\n", i);
            cnt[i]--;
        }
    }
    return 0;
}