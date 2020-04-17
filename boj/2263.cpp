#include <iostream>
#include <vector>
using namespace std;
vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;
vector<int> position;
int k = 0;
void solve(int is, int ie, int ps, int pe){
    int root = post_order[pe];
    if( is > ie || ps > pe){
        return;
    }
    printf("%d ", root);
    int p = position[root];
    int left = p - is;
    solve(is, p-1, ps, ps + left -1);
    solve(p+1, ie, ps+left, pe-1);
}

int main(){
    int n;
    cin>>n;
    in_order.reserve(n); post_order.reserve(n);
    pre_order.resize(n,0);
    position.resize(n+1,0);
    int element;
    //pre order?: Root->Left->Right
    for(int i = 0; i < n; i++){
        cin>>element;
        in_order.push_back(element);
        position[in_order[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin>>element;
        post_order.push_back(element);
    }
    solve(0, n-1, 0, n-1);
    return 0;
}