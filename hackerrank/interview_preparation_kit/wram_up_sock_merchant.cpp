using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> m;
    int count = 0;
    for(int i = 0; i < ar.size(); i++){
        m[ar[i]]++;
        if(m[ar[i]] == 2){
            count++;
            m[ar[i]] -= 2;
        }
    }
    return count;
}