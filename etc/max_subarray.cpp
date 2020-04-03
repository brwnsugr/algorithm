Write a program to find the largest sum of contiguous subarray within a one-dimensional array of integers.

(Examples)

Input: [2, 1, -3, 4]
Output: 4

Input: [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 7

Input: [2, 1, -10, 4]


d[i] : i 번째까지의 연속된 합의 최대값 

#include <vector>
int solution2(vector<int> input){
	//int sum = -1000000000;
	int n = input.size();
	int sum = 0;
	int answer = 0;
	for(int i = 0; i < n; ++i){
		if(sum + input[i] >= 0){
			sum = sum + input[i];
			answer = sum;
		}
		else if( sum + input[i] < 0){
			sum =0;
			continue;
		}
	}
	return answer;
}

using namespace std;
 // O(N^2)
int solution(vector<int> input){
	int n = input.size();
	int answer = 0;
	for(int i = 0; i < n; ++i){ 
		for(int j = i; j < n; ++j){ 
			int sum = 0;
			sum += input[j];
			if( answer < sum){
				answer = sum;
			}
	}
	return answer;
}
