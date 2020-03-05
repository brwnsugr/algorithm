int solution(vector<vector<int> > maps)
{
    const int dy[] = {-1,1,0,0};
    const int dx[] = {0,0,-1,1};
    int answer = 0;
    int h = maps.size();
    int w = maps[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(h, vector<int>(w,-1));
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    while(!q.empty()){
        pair<int, int> point = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_y = point.first+dy[i];
            int next_x = point.second+dx[i];
            if(next_y >= 0 && next_y < h
               && next_x >= 0 && next_x < w
               && maps[next_y][next_x] == 1){
                dist[next_y][next_x] = 1 + dist[point.first][point.second];
                if(next_y == h-1 && next_x == w-1){
                    return dist[next_y][next_x];
                }
                maps[next_y][next_x] = 0;
                q.push(make_pair(next_y,next_x));
            }
        }
    }
    answer = dist[h-1][w-1];
    return answer;
}