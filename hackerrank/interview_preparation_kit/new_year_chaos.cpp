void minimumBribes(vector<int> q) {
    int count = 0;
    for(int i = int(q.size())-1; i >= 0; i--){
        if(q[i]-(i+1) > 2){
            cout<<"Too chaotic"<<endl;
            return;
        }
        for(int j = max(0, q[i]-2); j < i; j++){
            if(q[j] > q[i]) count++;
        }
    }
    cout<<count<<endl;
    return;
}