#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> prime_set;
vector<int> dist(10001, 0);
vector<bool> check(10001, false);
vector<bool> mark(10001,false);
vector<pair<int,int>> paths;

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

void path(int &there){
    paths.push_back(make_pair(there, dist[there]));
    mark[there]= true;
    int count = dist[there]-1;
    if(count==0){
        return;
    }
    else{
        for(int i = 1000; i <= 9999; i++){
            if(dist[i]==count && !mark[i]){
                path(i);
            }
        }
    }
}

bool isThreedigitSame (){
    return true;
}

int main(){
    vector<bool> isPrime(10001, true);
    queue<int> q;
    isPrime[1] = false;
    primeCal(isPrime);
    int start, end;
    cin>>start>>end;
    q.push(start);
    cout<<start<<endl;
    check[start] = true;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now == end){
            break;
        }
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j <= 9; ++j){
                int there = change(now, i, j);
                if(there != -1){
                    if(!check[there] && isPrime[there]){
                        q.push(there);
                        check[there] = true;
                        dist[there] = dist[now] + 1;
                        if(there == end){
                            path(there);
                            cout<<there<<endl;
                            for(int i = 0; i < paths.size(); i++){
                                for(int j = dist[there]-1; j >= 0; --j){
                                    if(paths[i].second==j && isThreedigitSame){
                                        cout<<paths[i].first<<endl;
                                    } // 여기서 조건 함수를 하나 추가해서 숫자가 하나만 다른 조건이면 true로 던져주는 함수를 조건문 안에 넣습니다. 그 함수는 해쉬에 각 자리숫자를 담아서 3개만 일치하는 경우에 참인 조건을 출력하는 함수입니다.
                                }
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<dist[end]<<endl;
    return 0;
}