#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Student{
    string name;
    int korean;
    int english;
    int math;
};

bool compare_students(const Student &a, const Student b){
    if(a.korean == b.korean){
        if(a.english == b.english){
            if(a.math == b.math) return a.name < b.name;
            else return a.math > b.math;
        }
        else return a.english < b.english;
    }
    else return a.korean > b.korean;
}

int main(){
    int T; cin>>T;
    vector<Student> students;
    students.reserve(T);
    while(T--){
        string name;
        int korean; int english; int math;
        cin>>name>>korean>>english>>math;
        Student a = {name, korean, english, math};
        students.push_back(a);
    }
    sort(students.begin(), students.end(), compare_students);
    for(int i = 0; i < students.size(); i++){
        cout<<students[i].name<<'\n';
    }
    return 0;
}