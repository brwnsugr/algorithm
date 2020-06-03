using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count = 0;
    int len = int(s.length());
    int a_for_one_loop = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == 'a') a_for_one_loop++;
    }
    long q = n / len;
    int r = n % len;
    count += q * a_for_one_loop;
    for(int i = 0; i < r; i++){
        if(s[i] == 'a') count++;
    }
    return count;
}