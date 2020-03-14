#include <string>
#include <vector>
using namespace std;

void to_lowercase(vector<string> &cities){
    for(int i = 0; i < cities.size(); ++i){
        for(int j = 0; j < cities[i].length(); ++j){
            if(cities[i][j] >= 'A' && cities[i][j] <= 'Z'){
                cities[i][j] = cities[i][j] + 32;
            }
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cache_miss = 5;
    int cache_hit = 1;
    vector<string> cache;
    to_lowercase(cities);
    if(cacheSize==0) return cities.size() * cache_miss;
    for(int i = 0; i < cities.size(); ++i){
        //cache에 있는 경우
        bool inCache = false;
        for(int j = 0; j < cache.size(); ++j){
            if(cache[j] == cities[i]){
                //cache에 있고, 캐시가 꽉찬 경우
                cache.push_back(cities[i]);
                cache.erase(cache.begin() + j); inCache = true; answer += cache_hit;
                break;
            }
        }
        if(!inCache){
            //cache에 없고, 캐시가 꽉 찬 경우
            if(cache.size()== cacheSize){
                cache.erase(cache.begin());
                cache.push_back(cities[i]); answer += cache_miss;
            }
            // 캐시가 꽉차지 않은 경우
            else{
                cache.push_back(cities[i]); answer += cache_miss;
            }
        }
    }
    return answer;
}