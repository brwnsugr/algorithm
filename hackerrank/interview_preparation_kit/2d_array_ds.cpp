int hourglassSum(vector<vector<int>> arr) {
    int maxSum = -1000000;
    int height = int(arr.size());
    int width = int(arr[0].size());
    for(int i = 1; i < height - 1; i++){
        for(int j = 1; j < width - 1; j++){
            int sum = 0;
            sum += arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]; //윗줄 3칸
            sum += arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]; //아랫줄 3칸
            sum += arr[i][j]; //중앙
            if(sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}