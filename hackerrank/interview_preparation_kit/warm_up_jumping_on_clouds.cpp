using namespace std;

int jumpingOnClouds(vector<int> c) {
    //Greedy Algorithm Approach.. jumping further as much as I can at every time I Jump
    int jump_count = 0;
    int len = int(c.size());
    for(int i = 0; i < len - 1;){
        //두 칸 점프하는 경우(점프 했을 때 착지 인덱스가 마지막 인덱스 이하이고, 착지 인덱스가 번개가 아닌 경우)
        if(i+2 < len && c[i+2] != 1){
            i+=2; jump_count++;
        }
        //한 칸 점프하는 경우(점프 했을 때 착지 인덱스가 번개가 아닌 경우
        else if(i+1 < len && c[i+1] != 1){
            i+=1; jump_count++;
        }
    }
    return jump_count;
}