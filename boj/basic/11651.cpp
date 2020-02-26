//acmicpc.net
//sorting the location2
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{
    int x, y;
};

bool cmp(const Point &u, const Point &v){
    if(u.y<v.y){
        return true;
        }
    else if(u.y==v.y){
        return u.x<v.x;
        }
    else{
        return false;
        }
    }

int main(){
    int n;
    scanf("%d", &n);
    vector <Point> a(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i].x,&a[i].y);
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0; i<n; i++){
        cout<<a[i].x<<" "<<a[i].y<<'\n';
    }
    return 0;
}