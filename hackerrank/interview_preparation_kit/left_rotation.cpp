vector<int> rotLeft(vector<int> a, int d) {
    vector<int> tmp;
    queue<int> q;
    for(int i = 0; i < a.size(); i++){
        q.push(a[i]);
    }
    
    for(int j = 0; j < d; j++){
        int first = q.front();
        q.pop();
        q.push(first);
    }
    
    while(!q.empty()){
        tmp.push_back(q.front());
        q.pop();
    }
    return tmp;
}