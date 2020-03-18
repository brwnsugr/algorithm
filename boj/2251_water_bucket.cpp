#include<queue>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int A, B, C;
    vector<vector<bool>> check(201, vector<bool>(201,false));
    queue<pair<int,int>> q;
    set<int> s;
    check[0][0] = true;
    q.push(make_pair(0,0));
    cin>>A>>B>>C;
    int sum = C;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        int c_water = sum - a - b;
        
        if(a==0) s.insert(c_water);
        //A->B
        int next_a = 0, next_b = 0;
        if(a <= (B - b)){
            next_a = 0; next_b = a + b;
        }
        if(a > (B-b)){
            next_a = a - (B - b); next_b = B;
        }
        if(!check[next_a][next_b]){
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
        }
        //A->C
        if(a <= (C - c_water)){
            next_a = 0; next_b = b; 
        }
        if(a > (C-c_water)){
            next_a = a - (C-c_water); next_b = b; 
        }
        if(!check[next_a][next_b]){
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
        }
        //B->A
        if(b <= (A-a)){
            next_b = 0; next_a = a + b; 
        }
        if(b > (A-a)){
            next_b = b - (A-a); next_a = A; 
        }
        if(!check[next_a][next_b]){
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
        }
        //B->C
        if(b <= (C - c_water)){
            next_b = 0; next_a = a;
        }
        if(b > (C-c_water)){
            next_b = b - (C-c_water); next_a = a; 
        }
        if(!check[next_a][next_b]){
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
        }
        //C->A
        if(c_water <= (A-a)){
            next_b = b; next_a = a + c_water; 
        }
        if(c_water > (A-a)){
            next_a = A; next_b = b; 
        }
        if(!check[next_a][next_b]){
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
        }
        //C->B
        if(c_water <= (B-b)){
            next_b = b + c_water; next_a = a;
        }
        if(c_water > (B-b)){
            next_a = a; next_b = B; 
        }
    }
    for(auto it = s.begin(); it!= s.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}