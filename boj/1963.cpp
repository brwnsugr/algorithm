#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

void primeCal(vector<bool> &primes){
    for(int i = 2; i <= sqrt(10000); ++i){
        if(primes[i]){
            for(int j = i*i; j <= 10000; j+=i){
                primes[j] = false;
            }
        }
    }
}

int change(int &now, int &i, int &j){
    if( i == 0 && j == 0 ) return -1;
    string s = to_string(now);
    s[i] = j + '0';
    return stoi(s);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        vector<bool> check(10001, false);
        vector<bool> isPrime(10001, true);
        vector<int> dist(10001, 0);
        queue<int> q;
        isPrime[1] = false;
        primeCal(isPrime);
        int start, end;
        cin>>start>>end;
        q.push(start);
        check[start] = true;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int i = 0; i < 4; ++i){
                for(int j = 0; j <= 9; ++j){
                    int there = change(now, i, j);
                    if(there != -1){
                        if(!check[there] && isPrime[there]){
                            q.push(there);
                            check[there] = true;
                            dist[there] = dist[now] + 1;
                        }
                    }
                }
            }
        }
        cout<<dist[end]<<endl;
    }
    return 0;
}