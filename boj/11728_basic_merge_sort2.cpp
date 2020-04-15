#include <vector>
#include <stdio.h>
using namespace std;
void merge(vector<int>& left, vector<int>& right, vector<int>& sorted_vec){
    int len_left = int(left.size());
    int len_right = int(right.size());
    int i = 0; int j = 0; int k = 0;
    while(i < len_left && j < len_right){
        if(left[i] <= right[j]) sorted_vec[k++] = left[i++];
        else sorted_vec[k++] = right[j++];
    }
    while(i < len_left) sorted_vec[k++] = left[i++];
    while(j < len_right) sorted_vec[k++] = right[j++];
}

int main(){
    int N, M;
    scanf("%d", &N); 
    scanf("%d", &M);
    vector<int> left; vector<int> right;
    left.reserve(N); right.reserve(M);
    for(int i = 0; i < N; i++){
        int left_element; scanf("%d", &left_element);
        left.push_back(left_element);
    }
    for(int j = 0; j < M; j++){
        int right_element; scanf("%d", &right_element);
        right.push_back(right_element);
    }
    vector<int> sorted_vec(N+M);
    merge(left, right, sorted_vec);
    for(int i = 0; i < int(sorted_vec.size()); i++){
        printf("%d ", sorted_vec[i]);
    }
    return 0;
}