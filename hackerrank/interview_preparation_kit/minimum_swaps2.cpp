int minimumSwaps(vector<int> arr) {
    int diff_count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != i+1){
            int t = i;
            while(arr[t] != i+1){
                t++;
            }
            int tmp = t;
            swap(arr[i], arr[tmp]);
            diff_count++;
        }
    }
    return diff_count;
}