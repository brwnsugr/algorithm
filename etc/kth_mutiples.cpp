// Let Assume that N is proportional to K.(K'th element) 
// Time Complexity: O(N*log(N))
// Space Complexity: O(N)

#include <set>
#include <iostream>

using namespace std;
int main(){
    int A, B, K;
    cin>>A>>B>>K;
    set<int> s;
    int multiply = 1;
    if(K==1){
        cout<<A; return 0;
    }
    while(true){
        s.insert(A*multiply);
        if(s.size()==K) {
            cout<<*s.rbegin();
            break;
        }
        s.insert(B*multiply);
        if(s.size()==K){
            cout<<*s.rbegin();
            break;
        }
        multiply++;
    }
    return 0;
}