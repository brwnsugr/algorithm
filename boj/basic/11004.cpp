#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[5000000];
int main(){
    int N, K; cin>>N>>K;
    K--;
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    nth_element(a, a+K, a+N);
    printf("%d", a[K]);
    return 0;
}