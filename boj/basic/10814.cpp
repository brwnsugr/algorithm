//acmicpc.net
//sorting by age
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Person{
    int age;
    string name;
};

bool cmp(const Person &u, const Person &v){
    return u.age<v.age ;
}

int main(){
    int n;
    scanf("%d", &n);
    vector <Person> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].age>>a[i].name;
          }
    stable_sort(a.begin(),a.end(),cmp);
    for(int i=0; i<a.size(); i++){
        cout<<a[i].age<<" "<<a[i].name<<'\n';
    }
    return 0;
}