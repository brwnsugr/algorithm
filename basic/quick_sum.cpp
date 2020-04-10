#include <iostream>
using namespace std;

int fast_sum(int n){
    if(n == 1) return 1;
    else if(n % 2 == 1) return fast_sum(n - 1) + n;
    else return 2*fast_sum(n/2) + (n*n/4);
}

int main(){
    cout<<fast_sum(10);
    return 0;
}